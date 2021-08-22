/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "Simulation.h"
//----------------------------------------------

// -- Reading the Trains txt file
// -----------------------------------------
//	Checking if open
//  Pushing the trains from the txt file into Vtrain vector
// -----------------------------------------
void Simulation::readTrainsFile()
{
	//opening file
	ifstream infile("src/Trains.txt");

	if (infile.is_open())
	{

		string line;
		while (getline(infile, line))  //Reading line
		{
			istringstream iss(line);     //putting the line into a istringstream
			int shour, smin, ehour, emin;
			int pId;
			string pDepartureStation;
			string pDestinationStation;
			int pDepartureTime;
			char pColumn;
			int pDestinationTime;

			int speed;
			int type;

			//outputting the istringsteram to the variables
			iss >> pId >> pDepartureStation >> pDestinationStation >> shour >> pColumn >> smin >> ehour >> pColumn >> emin >> speed;

			//Converting the time to minutes
			pDepartureTime = (shour * 60) + smin;
			pDestinationTime = (ehour * 60) + emin;

			//emptying the types from the line
			while (iss >> type)
			{
				//Saving into a temporary vector
				typeStorage.push_back(type);
			}
			//Putting the train into Vtrain
			Vtrain.push_back(unique_ptr<Train>(new Train(pId, pDepartureStation, pDestinationStation, pDepartureTime, pDestinationTime, speed, move(typeStorage))));
			iss.str(""); //Emptying the istringstream
		}
	}
	else
	{
		cout << "Error opening file!";
	}
}
// -- Reading the TrainStations txt file
// -----------------------------------------
//	Checking if open
//  Finding the name of the station
//  Modifying the text file to make easier to work with
// -----------------------------------------
void Simulation::readTrainStationFile()
{

	ifstream infile("src/TrainStations.txt");

	if (infile.is_open())
	{

		string line;

		while (getline(infile, line))
		{
			int id, type, param0, param1;
			string station;
			//Substracting the station name
			station = line.substr(0, line.find(" "));
			shared_ptr<Station> pStation(new  Station(station));

			//Modifying the lines
			line = line.substr(line.find_first_of(" \t") + 1);
			line.erase(remove(line.begin(), line.end(), '('), line.end());
			replace(line.begin(), line.end(), ')', ' ');

			// putting the line in a istringstream
			istringstream iss(line);

			//While id is found
			while (iss >> id)
			{
				iss >> type;
				if (type == 0)
				{
					iss >> param0 >> param1;
					pStation->pushBackCar(id, type, param0, param1);  //pushing back into Vcar depending on id
				}
				else if (type == 1)
				{
					iss >> param0;
					pStation->pushBackCar(id, type, param0, param1);
				}
				else if (type == 2)
				{
					iss >> param0 >> param1;
					pStation->pushBackCar(id, type, param0, param1);
				}
				else if (type == 3)
				{
					iss >> param0;
					pStation->pushBackCar(id, type, param0, param1);
				}
				else if (type == 4)
				{
					iss >> param0 >> param1;
					pStation->pushBackCar(id, type, param0, param1);
				}
				else if (type == 5)
				{
					iss >> param0 >> param1;
					pStation->pushBackCar(id, type, param0, param1);
				}
			}
			Vstation.push_back(move(pStation)); //pushing back into Vstation with the use of move
		}
		copyVectorVstation(); // Copying the Vstation to get the start positions of all the Cars in each station
		infile.close();
	}
	else
	{
		cout << "Error opening file!";
	}
}

// -- Reading the TrainMap txt file
// -----------------------------------------
//	Checking if open
//  Pushing back into VtrainMap
//  Try and cach included
// -----------------------------------------

void Simulation::readTrainMapFile()
{
	ifstream infile("src/TrainMap.txt");	
	
	if (infile.is_open())
	{

		string line;
		while (getline(infile, line))
		{
			istringstream iss(line);

			string pStation1;
			string pStation2;
			int pDistance;

			iss >> pStation1 >> pStation2 >> pDistance;

			VtrainMap.push_back(unique_ptr<TrainMap>(new TrainMap(pStation1, pStation2, pDistance)));
			iss.str("");
		}
		infile.close();
	}
	else
		cout <<"error reading file";
}
// -- Moving Train Vector to eventQueue
// -----------------------------------------
//	while Vtrain is not empty
//  EventQueue pushign into NotAssembled
//  with help of a popVector function
// -----------------------------------------

void Simulation::moveTrainVectorToQueue()
{
	while (!isEmpty())
	{
		eventQueue.push(unique_ptr<NotAssembled>(new NotAssembled(popVector())));
	}
}
// -- Is Vtrain empty 
// -----------------------------------------
//  returning true or false
// -----------------------------------------
bool Simulation::isEmpty()
{
	return Vtrain.empty();
}

// -- Returning back of Vtrain and popping it
// -----------------------------------------
//	Creating a tmp shared_ptr and setting it = Vtrain.Back
//  Popping Vtrain.back and returning tmp
// -----------------------------------------
shared_ptr<Train> Simulation::popVector()
{
	shared_ptr<Train> tmp;
	tmp = Vtrain.back();
	Vtrain.pop_back();
	return tmp;
}

// -- Reading files moveTrainVectorToQueue and copying Vtrain
// -----------------------------------------
//	Starting functions
// -----------------------------------------
void Simulation::readFiles()
{
	readTrainsFile();
	readTrainStationFile();
	readTrainMapFile();
	copyVectorVtrain();
	moveTrainVectorToQueue();
}

// -- sceduleEvent
// -----------------------------------------
//	EventQueue pushing to newEvent
// -----------------------------------------
void Simulation::scheduleEvent(shared_ptr<Event> newEvent)
{
	eventQueue.push(newEvent);
}

// -- Running the events with Intervals
// -----------------------------------------
//	while eventQuene not emptyy and current time is less than simEndTime
//  Getting the time of the NextEvent
//  If current time is less than simStartTime
//  pop the eventQueue and process it
//  Else if currentime is equal or bigger than start time but less than sim start time+interval
//  Do the same as above but this time print the event
//  Else letting the user continue the interval run or typeign exit to return to menu
// -----------------------------------------
bool Simulation::runNextInterval(shared_ptr<Simulation> &sim)
{
	int tmpInterval = interval;

	cout << "2.Run next interval" << endl;
	cout << "---------------------" << endl << endl;
	cout << "Current time " << convertIntMinToString(simStartTime) << endl << endl;

	// setting next event to eventQueue top and setting the currentTime to nextEvent->getTime
	shared_ptr<Event>  nextEvent = eventQueue.top();
	currentTime = nextEvent->getTime();

	while (!eventQueue.empty() && currentTime < simEndTime)
	{

		shared_ptr<Event>  nextEvent = eventQueue.top();
		currentTime = nextEvent->getTime();


		if (currentTime < simStartTime)
		{
			eventQueue.pop();
			nextEvent->processEvent(sim);
		}
		else if (currentTime >= simStartTime && currentTime < simStartTime + tmpInterval)
		{
			eventQueue.pop();
			nextEvent->processEvent(sim);
			nextEvent->print(getLogLevel());  //printing if the event is in the time limits
		}
		else
		{
			string input;
			cout << endl << "-----------------------;" << endl;
			cout << "Type (exit) to return to menu:";
			getline(cin, input);

			if (input == "exit")
			{
				return true;
			}
			tmpInterval = tmpInterval + interval; //Increasing the intervals so that it dosent get stuck
			cout << endl << "Current interval time " << convertIntMinToString(simStartTime + tmpInterval) << endl;
		}

	}
	returnToMenu();

}

// -- Running the next event
// -----------------------------------------
//	while eventQuene not emptyy and current time is less than simEndTime
//  Process the events
//  after the while loop check ikf currentTime is less  than simEndTime
//  If yes process the event and print it out and letting the 
//  Else currentTime has passed sim end time
// -----------------------------------------
void Simulation::nextEvent(shared_ptr<Simulation> &sim)
{
	cout << "3.Next event" << endl;
	cout << "---------------------" << endl << endl;

	shared_ptr<Event>  nextEvent = eventQueue.top();
	currentTime = nextEvent->getTime();
	cout << "Current time " << convertIntMinToString(currentTime) << endl;

	while (!eventQueue.empty() && currentTime < simStartTime)
	{
		shared_ptr<Event>  nextEvent = eventQueue.top();
		currentTime = nextEvent->getTime();
		eventQueue.pop();
		nextEvent->processEvent(sim);
	}
	if (currentTime < simEndTime)
	{
		eventQueue.pop();
		nextEvent->processEvent(sim);
		nextEvent->print(getLogLevel()); //printing		
	}
	else
	{		
		cout << "Current time has passed sim end time! To see finish the simulation pick menu option 4.Finish" << endl;
		cout << "Current time:" << convertIntMinToString(simEndTime) << endl;
		cout << "Sim End time:" << convertIntMinToString(simEndTime) << endl;
	}
	returnToMenu();
}

// -- Running Finished (complete events)
// -----------------------------------------
//	while eventQueue is not empty
//  if currenTime is < simStartTime
//  pop and proccessEvent
//  Else pop and proccessEvent with printing
// -----------------------------------------
void Simulation::finished(shared_ptr<Simulation> &sim)
{	
	cout << "4.Finish (Complete simulation)" << endl;
	cout << "---------------------" << endl << endl;
	cout << "Current time " << convertIntMinToString(simStartTime) << endl;

	while (!eventQueue.empty())
	{

		shared_ptr<Event>  nextEvent = eventQueue.top();
		currentTime = nextEvent->getTime();


		if (currentTime < simStartTime)
		{

			eventQueue.pop();
			nextEvent->processEvent(sim);
		}
		else //Printing out the rest of the simulation until eventQueue is done
		{
			eventQueue.pop();
			nextEvent->processEvent(sim);
			nextEvent->print(getLogLevel());
		}
	}
	cout << "Current time " << convertIntMinToString(simEndTime) << endl << endl;
	returnToMenu();
}


// -- Setting simStartTime
// -----------------------------------------
//	Converting the string input to int minutes
//  if the tmpSimStartTime is less than simEndTime and bigger than 0(automaticly set to 0)
//  and less than 24 hours then setting the simStartTime to the input
//  Else return false
// -----------------------------------------
bool Simulation::setSimStartTime(string pSimStartTime)
{
	int tmpSimStartTime = 0;

	tmpSimStartTime = convertInputTimeToMin(pSimStartTime); //Converting input to minutes

	if (tmpSimStartTime < simEndTime && tmpSimStartTime > 0 && tmpSimStartTime < 1440)  //Checking limits
	{
		simStartTime = convertInputTimeToMin(pSimStartTime); //Converting the time to int minutes
		return true;
	}
	else
	{
		cout << "Wrong input, try again!" << endl;
		cin.get();
		return false;
	}

}

// -- Setting simEndTime
// -----------------------------------------
//	Converting the string input to int minutes
//  if tmpSimEndTime is bigger than simStartTime and bigger than 0
//  then setting the simEndTime to the input
//  Else return false
// -----------------------------------------
bool Simulation::setSimEndTime(string pSimEndTime)
{

	int tmpSimEndTime = 0;

	tmpSimEndTime = convertInputTimeToMin(pSimEndTime);

	if (tmpSimEndTime > simStartTime &&  tmpSimEndTime > 0)
	{
		simEndTime = convertInputTimeToMin(pSimEndTime);
		return true;
	}
	else
	{
		cout << "Wrong input, try again!" << endl;
		cin.get();
		return false;
	}
}

// -- Setting simEndTime
// -----------------------------------------
//	Converting the string input to int minutes
//  if tmpinterval is less than simEndTime and less than 1439 min
//  then setting the interval to the input
//  Else return false
// -----------------------------------------
bool Simulation::setInterval(string pInterval)
{
	int tmpInterval = 0;

	tmpInterval = convertInputTimeToMin(pInterval);

	if (tmpInterval < simEndTime && tmpInterval < 1439)
	{
		interval = convertInputTimeToMin(pInterval);
		return true;
	}
	else
	{
		cout << "Wrong input, try again!" << endl;
		cin.get();
		return false;
	}
}

// -- Setting log level
// -----------------------------------------
//	If less than 3 set it to input and return true
// -----------------------------------------
bool Simulation::setLogLevel(logLevel pLl)
{
	if (pLl < 3)
	{
		ll = pLl;
		return true;
	}
	else
	{
		return false;
	}
}

// -- Statistics
// -----------------------------------------
//	First going through the VcopyStation vector and printing the station names and VcarSize (how many cars are in the station)
//  Adding everything together in the int VtotalDelayTime vector to get the total delay time with a iterator
//  Printing out the vector Vnlts (trains that never left the station)
//  Printing out the vector Vdelayed (trains that got delayed)
// -----------------------------------------
void Simulation::statistics(shared_ptr<Simulation> &sim)
{
	//Getting station names and size of cars within that station
	cout << "Number of vehicles at start of simulation:" << endl;
	for (int i = 0; i < VcopyStation.size(); i++)
	{
		cout << "Station name: " << VcopyStation[i]->getStationName() << " = " << VcopyStation[i]->VcarSize() << endl;
	}

	//Getting the sum of all the delayed trains
	int sum = 0;
	for (vector<int>::iterator it = VtotalDelayTime.begin(); it != VtotalDelayTime.end(); ++it)
	{
		sum += *it;
	}

	//Facts
	cout << endl << "Results at end of simulation:" << endl;
	cout << "End time for simulation: " << convertIntMinToString(simEndTime) << endl;
	cout << "Total delay time: " << convertIntMinToString(sum) << endl << endl;

	//Printing out the trains that never left the station
	cout << "Trains that never left the station (" << Vnlts.size() << ")" << endl;
	for (auto &e : Vnlts)
	{
		e->print(getLogLevel());
	}

	//Printing out the trains that got delayed
	cout << endl << "Delayed trains(" << Vdelayed.size() << "):" << endl << endl;
	for (auto &e : Vdelayed)
	{
		e->print(getLogLevel());
	}
	returnToMenu();
}

// -- making a copy of Vstation
// -----------------------------------------
//	Copying vector Vstation to VcopyStation
// -----------------------------------------
void Simulation::copyVectorVstation()
{
	//copying vector Vstation
	for (const auto& e : Vstation)
		VcopyStation.push_back(make_shared<Station>(*e));
}

// -- making a copy of Vtrain
// -----------------------------------------
//	Copying vector Vtrain to VcopyTrain
// -----------------------------------------
void Simulation::copyVectorVtrain()
{
	//copying vector Vtrain
	for (const auto& e : Vtrain)
		VcopyTrain.push_back(make_shared<Train>(*e));
}

// -- Pushing back into vectors
// -----------------------------------------
//	Vnlts : Trains that never left the station
//  Vdelayed : Trains that got delayed
//  VtrainByCarId : Trains that get assembled
//  Vch: Trains in every stage of the event to see the history of the car
//  VtotalDelayTime : The delay time of each train inside the events: done after the delay time is calc
// -----------------------------------------
void Simulation::neverLeftTheStationTrains(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay)
{
	Vnlts.push_back(shared_ptr<NeverLeftTheStation>(new NeverLeftTheStation(pid, pdepartureStation, pdestinationStation, pdepartureTime, pdestinationTime, pspeed, ptime, pVint, VhistoryCar, pDelay, ptotalDelay)));
}
void Simulation::delayedTrains(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay)
{
	Vdelayed.push_back(shared_ptr<Delayed>(new Delayed(pid, pdepartureStation, pdestinationStation, pdepartureTime, pdestinationTime, pspeed, ptime, pVint, VhistoryCar, pDelay, ptotalDelay)));
}
void Simulation::searchTrainByCarId(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay)
{
	VtrainByCarId.push_back(shared_ptr<TrainByCarId>(new TrainByCarId(pid, pdepartureStation, pdestinationStation, pdepartureTime, pdestinationTime, pspeed, ptime, pVint, VhistoryCar, pDelay, ptotalDelay)));
}
void Simulation::carHistory(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay, string pState)
{
	Vch.push_back(shared_ptr<CarHistory>(new CarHistory(pid, pdepartureStation, pdestinationStation, pdepartureTime, pdestinationTime, pspeed, ptime, pVint, VhistoryCar, pDelay, ptotalDelay, pState)));
}
void Simulation::totalDelayTime(int x)
{
	VtotalDelayTime.push_back(x);
}
// -----------------------------------------
// -----------------------------------------


// -- Finding speed of each Car: (not used in program!)
// -----------------------------------------
//	Was to find max speed of each car
//  I thought I had to use it to calc the speed of the trains
// -----------------------------------------
int Simulation::findSpeed(vector <shared_ptr<Car>> pCar)
{
	int pSpeed = 0;

	for (auto &e : pCar)
	{
		if (e->getType() == 4 || e->getType() == 5)
		{
			pSpeed = e->getParam0();
		}
		return pSpeed;
	}
}


// -- Finding minutes
// -----------------------------------------
//	using departue time, destination time and delay
//  I thought I had to use it to calc the speed of the trains
// -----------------------------------------
int Simulation::findMinutes(int pdeptime, int pdestime, int pdelay)
{
	int startTime = pdeptime + pdelay;
	int destTime = pdestime;
	int totalMin = destTime - startTime;

	return totalMin;
}

// -- Finding distance
// -----------------------------------------
//	just going through VtrainMap and using if statments if station 1 and 2 match
//  Since the txt file is set up in a special way i need to check 2 times
// -----------------------------------------
int Simulation::findDistance(string pDepartureStation, string pDestinationStation)
{
	int pDistance;

	for (auto &e : VtrainMap)
	{
		if (e->getStation1() == pDepartureStation && e->getStation2() == pDestinationStation) //station1 && station2 to match
		{
			pDistance = e->getDistance();
			return pDistance;
		}
		else if (e->getStation2() == pDepartureStation && e->getStation1() == pDestinationStation) //station2 && station1 match
		{
			pDistance = e->getDistance();
			return pDistance;
		}
	}
}

// -- Finding carType in station
// -----------------------------------------
//	looping through Vstation to find station name
//  If station name found. going deeper to Station Class and search there for the car
//  searchforcar will return a pointer, so either the pointer of the car or nullptr
//  If car is found the pointer is returned and the pointer in the station is deleted
//  since now ther car in in a train and not the station anymore
// -----------------------------------------
shared_ptr<Car> Simulation::findCarTypeInStation(string pStation, int pCarType)
{

	for (int i = 0; i < Vstation.size(); i++)
	{

		if (pStation == Vstation[i]->getStationName())
		{

			return Vstation[i]->searchforcar(pStation, pCarType);
		}
	}
	return nullptr;  //if nothing found
}

// -- Finding car by its id
// -----------------------------------------
//	Letting the user input a integer (id) that he wants to search for
//  then searching through Vstation and going deeper to Vcar and searching there
//  If found the searchForCarById will print it out
// -----------------------------------------
void Simulation::findCarById()
{
	cin.get();
	int x;
	cout << "Search for car:";
	cin >> x;

	for (int i = 0; i < Vstation.size(); i++)
	{
		Vstation[i]->searchForCarById(getLogLevel(), x);
	}
	returnToMenu();
}

// -- Finding train by car id
// -----------------------------------------
//	looping thorugh the VtrainByCarId vector
//  then searching through function searchForCarInVhistoryCar
//  If it returns true print the train
// -----------------------------------------
void Simulation::findTrainByCar()
{
	shared_ptr<Station> tmp;

	int x = 0;
	cout << "Type the id of Car you want to search for:";
	cin >> x;

	for (auto &e : VtrainByCarId)
	{
		if (e->searchForCarInVhistoryCar(x)) //Returning true or false
		{
			e->print(getLogLevel());
		}
	}
	returnToMenu();
}

// -- Showing the history of Car
// -----------------------------------------
//	looping thorugh the Vch vector
//  then searching through function searchForCarInVhistoryCar
//  If it returns true print the train
// -----------------------------------------
void Simulation::showHistoryOfCar()
{
	shared_ptr<Station> tmp;

	int x = 0;
	cout << "Type the id of Car you want to see history for:";
	cin >> x;

	for (auto &e : Vch)
	{
		if (e->searchForCarInVhistoryCar(x))
		{
			e->print(getLogLevel());
		}
	}
	returnToMenu();
}

// -- Show all trains
// -----------------------------------------
//	Looping through VcopyTrain and printing out all trains
// -----------------------------------------
bool Simulation::showAllTrains()
{
	cout << "All trains:" << endl;


	for (auto i = 0; i < VcopyTrain.size(); i++)
	{
		typeStorage = VcopyTrain[i]->getVcarTypes(); //getting the VcarTypes and putting it in typeStorage vector

		cout << VcopyTrain[i]->getId() << " " << VcopyTrain[i]->getDepartureStation() << " "
			<< VcopyTrain[i]->getDestinationStation() << " " << convertIntMinToString(VcopyTrain[i]->getDepartureTime()) << " "
			<< convertIntMinToString(VcopyTrain[i]->getDestinationTime()) << " " << VcopyTrain[i]->getSpeed() << " ";

		//printing out the typeStorage vector
		for (auto i = 0; i < typeStorage.size(); i++)
		{
			cout << typeStorage[i] << " ";
		}
		cout << endl;

	}
	returnToMenu();
	return true;
}

// -- Searching for Train by Id(number)
// -----------------------------------------
//	user input to search for a specific id
//  looping through VcopyTrain and see if input and a train id match
//  If yes print it out and return true
//  Else return false
// -----------------------------------------
bool Simulation::searchTrainByNumber()
{
	int input = 0;
	cout << "Search train by number:";
	cin >> input;

	//looping the vector
	for (auto i = 0; i < VcopyTrain.size(); i++)
	{
		if (input == VcopyTrain[i]->getId()) //Checking if match
		{
			cout << "Train was found:" << endl;
			typeStorage = VcopyTrain[i]->getVcarTypes();  //getting the VcarTypes and putting it in typeStorage vector

			cout << VcopyTrain[i]->getId() << " " << VcopyTrain[i]->getDepartureStation() << " "
				<< VcopyTrain[i]->getDestinationStation() << " " << convertIntMinToString(VcopyTrain[i]->getDepartureTime()) << " "
				<< convertIntMinToString(VcopyTrain[i]->getDestinationTime()) << " " << VcopyTrain[i]->getSpeed() << " ";

			//printing out the typeStorage vector
			for (auto i = 0; i < typeStorage.size(); i++)
			{
				cout << typeStorage[i] << " ";
			}
			returnToMenu();
		}
	}
	cout << "Train was not found" << endl;
	return false;
}

// -- Returning the cars to the destination station
// -----------------------------------------
//	arguments are the destinationstation and the VhistoryCar vector
//  Checking if station match
//  If yes pushing back the cars to that station
// -----------------------------------------
void Simulation::ReturnCarsToStations(string pStationName, vector <shared_ptr<Car>> pCar)
{
	int id, type, param0, param1;


	for (int i = 0; i < Vstation.size(); i++)
	{
		if (Vstation[i]->getStationName() == pStationName) //Checking station name
		{
			for (auto &e : pCar)
			{
				Vstation[i]->pushBackCar(e->getId(), e->getType(), e->getParam0(), e->getParam1());  //Pushing back the cars
			}
		}
	}
}

// -- Showing station names
// -----------------------------------------
//	looping through the Vstation vector and printing out the station names
// -----------------------------------------
void Simulation::ShowStationNames()
{
	cout << "Station names" << endl;
	for (int i = 0; i < Vstation.size(); i++)
	{
		cout << i + 1 << ". " << Vstation[i]->getStationName() << endl;
	}
	returnToMenu();
}

// -- Showing station by name
// -----------------------------------------
//	getting input from user to search with
//  looping the Vstation vector to find a match
// -----------------------------------------
bool Simulation::ShowStationByName()
{
	cin.get();
	string input;
	cout << "Search for station:";
	getline(cin, input);

	for (int i = 0; i < Vstation.size(); i++)
	{
		if (input == Vstation[i]->getStationName())  //if found
		{
			cout << "Station found: ";
			cout << Vstation[i]->getStationName();
			returnToMenu();
			return true;
		}
	}
	cout << endl << "No station found with that name";
	return false;
}

// -- Showing station and all cars
// -----------------------------------------
//	Looping Vstation and printing out the station name
//  then using function getCars that prints the cars of that station
// -----------------------------------------
void Simulation::ShowAllStationsAndCars()
{
	cout << "Station names:" << endl;
	for (int i = 0; i < Vstation.size(); i++)
	{
		cout << i + 1 << ". " << Vstation[i]->getStationName() << endl;
		Vstation[i]->getCars(getLogLevel());
		cout << "----------------------------------------" << endl;
	}
	returnToMenu();
}

// -- Printing all cars
// -----------------------------------------
//	Looping Vstation 
//  then using function getCars that prints the cars
// -----------------------------------------
void Simulation::AllCars()
{
	cout << "All cars in the simulator:" << endl;
	for (int i = 0; i < Vstation.size(); i++)
	{
		Vstation[i]->getCars(getLogLevel());
	}
	returnToMenu();
}


// -- Calculating avrage speed
// -----------------------------------------
//	using mintues and distance
//  Basic formula: speed = distance/time
// -----------------------------------------
int Simulation::calcAvgSpeed(int pMin, int pDistance)
{
	int x = 60; 
	float min = pMin;
	float dis = pDistance;
	int avgSpeed = 0;
	float y;

	y = x / min;  
	avgSpeed = y*pDistance;
	return avgSpeed;
}

// -- Calculating the delay time
// -----------------------------------------
//	using distance speed depaterue time destination time and delay time
// -----------------------------------------
int Simulation::calcDelayTime(int pDistance, int pSpeed, int pDepartureTime, int pDestinationTime, int pDelay)
{
	int delayTime = 0;

	double speed = pSpeed;
	double distance = pDistance;
	int depTime = pDepartureTime;
	int destTime = pDestinationTime;
	int delay = pDelay;

	double x, y, z;

	x = (distance / speed) * 60;   // Time = (distance/speed) * 60 since calc in minutes
	y = destTime - depTime;  //mintues it takes from destination station to departure station
	z = y - x;               // so time - (des-dep) time
	delayTime = delay - z;   // then the new delay time will be the old delay time - the new delay time
	return delayTime;
}

// -- Converters
// -----------------------------------------
//	Converting string input to minutes
//  Converting int minutes to string output
//  Converting log level to string text
// -----------------------------------------
int Simulation::convertInputTimeToMin(string pTime)
{
	int day, hr, min, totalMin;
	string input = pTime;

	replace(input.begin(), input.end(), ':', ' ');
	istringstream iss(input);
	iss >> day >> hr >> min;
	day = day * 24 * 60;
	hr = hr * 60;
	totalMin = day + hr + min;
	return totalMin;
}
string Simulation::convertIntMinToString(int pMin)
{
	stringstream ss;

	int hr = (pMin / 60) % 24;
	int min = pMin % 60;
	int day = (pMin / 60) / 24;

	if (pMin < 1440) // less than a day
	{
		ss << "[" << setw(2) << setfill('0') << hr << ':'
			<< setw(2) << setfill('0') << min << "]";
		return ss.str();
	}
	else       // more than a day
	{
		ss << "[" << setw(2) << setfill('0') << day << ':'
			<< setw(2) << setfill('0') << hr << ':'
			<< setw(2) << setfill('0') << min << "]";
		return ss.str();
	}
}
string Simulation::convertLogLevelToString(int pMin)
{
	int pLoglevel = pMin;
	string low = "low", medium = "medium", high = "high";

	stringstream ss;

	if (pLoglevel == 0)
	{
		ss << "[" << low << "]";
		return ss.str();
	}
	if (pLoglevel == 1)
	{
		ss << "[" << medium << "]";
		return ss.str();
	}
	if (pLoglevel == 2)
	{
		ss << "[" << high << "]";
		return ss.str();
	}
}



























