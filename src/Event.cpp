/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "Event.h"
#include "Simulation.h"
//----------------------------------------------

//----------------------------------------------
//Constructors
//----------------------------------------------
NotAssembled::NotAssembled(shared_ptr<Train> tmp)
{
	//Setting all the parameters 
	id = tmp->getId();										
	departureStation = tmp->getDepartureStation();
	destinationStation = tmp->getDestinationStation();
	departureTime = tmp->getDepartureTime();
	destinationTime = tmp->getDestinationTime();
	speed = tmp->getSpeed();
	Vint = tmp->getVcarTypes();
	time = tmp->getDepartureTime() - Constants::assembleTime;   //Train starting assembling 30 mins before
}

Incomplete::Incomplete(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	delay = pDelay + Constants::incompleteTime;
	totalDelay = ptotalDelay;
	time = ptime + Constants::incompleteTime;   //+10 mins for next try
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
}

Assembled::Assembled(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime + Constants::readyTime;  //+20 mins to reach ready state
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;

}

Ready::Ready(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime + Constants::runningTime; //10 min to reach running state
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;

}

Running::Running(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = pdestinationTime;  //Set to destination time
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;

}

Arrived::Arrived(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = pdestinationTime + pDelay + Constants::disassembleTime;  //Set to destination time + delay + disassembleTime
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;
}

Finished::Finished(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime;
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;
}

Delayed::Delayed(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime;
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;
}

NeverLeftTheStation::NeverLeftTheStation(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime;
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;
}

TrainByCarId::TrainByCarId(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime;
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;
}

CarHistory::CarHistory(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> pVhistoryCar, int pDelay, int ptotalDelay,string pState)
{
	id = pid;
	departureStation = pdepartureStation;
	destinationStation = pdestinationStation;
	departureTime = pdepartureTime;
	destinationTime = pdestinationTime;
	speed = pspeed;
	time = ptime;
	Vint = pVint;
	VhistoryCar = pVhistoryCar;
	delay = pDelay;
	totalDelay = ptotalDelay;
	state = pState;
}
//----------------------------------------------
//----------------------------------------------


// -- Processing NotAssembled Event
// -----------------------------------------
//	First Vint needs to be reversed and then check if Vint is containing any element;
//  If yes, x is set to the back element of Vint and then departurestation and x are used for locating a Car  
//  If a carType is located at the station, the car gets pushed back into VhistoryVector and Vint gets pop.back()
//  and size gets 1 lower. When size reaches 0. A check is made to see if Vint is empty.
//  if yes, the train will be moved to Assembled, if not it will be moved to Incomplete
// -----------------------------------------
void NotAssembled::processEvent(shared_ptr<Simulation> &sim)
{
	int x;
	int size;

	//Tmp pointer
	shared_ptr<Car> tmpCar;

	reverse(Vint.begin(), Vint.end());  //Reversing Vint

	size = Vint.size(); //Setting size to the Vint size
	while (size > 0)
	{
		x = Vint.back(); 

		//using a return shared_ptr<Car> function to locate a car, tmpCar will be set to that ptr
		//if not found in station nullptr get returned
		tmpCar = sim->findCarTypeInStation(departureStation, x); 
		if (tmpCar != nullptr)
		{
			VhistoryCar.push_back(tmpCar);  //Pushing into the VhistoryCar, this has to be done to know the history since Vint gets poped
			Vint.pop_back(); //popping vint				
		}
		size--;
	}

	if (Vint.empty())
	{
		state = "Assembled";

		//Sceduleing the new event
		sim->scheduleEvent(shared_ptr<Assembled>(new Assembled(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));		
		
		//function that pushes back the object, to locate the train with a specific car. This is only used in assembled		
		sim->searchTrainByCarId(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay);

		//Same as above, but this will be used in all Events to get the history movement of a specific car
		sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay, state);
	}
	else
	{
		state = "Incomplete";
		delay = delay + Constants::incompleteTime; //Setting delay time to +10 mins
		sim->scheduleEvent(shared_ptr<Incomplete>(new Incomplete(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));		
		sim->searchTrainByCarId(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay);
		sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay, state);
	}
}


// -- Processing Incomplete Event
// -----------------------------------------
//	checking if time is less that 24 hours, if yes try to Assemble again, if no push back the Train into NeverLeftTheStation vector
//  Doing the same as in NotAssembled, difference is here that Vint only contains the Cars that didnt get poped
// ---------------------------------------- -
void Incomplete::processEvent(shared_ptr<Simulation> &sim)
{
	if (time < 1410)
	{

		int x;
		int size;

		reverse(Vint.begin(), Vint.end());


		shared_ptr<Car> tmpCar;

		size = Vint.size();
		while (size > 0)
		{
			x = Vint.back();
			tmpCar = sim->findCarTypeInStation(departureStation, x);
			if (tmpCar != nullptr)
			{
				VhistoryCar.push_back(tmpCar);
				Vint.pop_back();

			}
			size--;
		}

		if (Vint.empty())
		{
			state = "Assembled";
			delay = delay - Constants::incompleteTime; //Delay time needs to be -10 min, since the constructor sets +10 for incomplete
			sim->scheduleEvent(shared_ptr<Assembled>(new Assembled(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));
			sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
		}
		else
		{
			state = "Incomplete";
			sim->scheduleEvent(shared_ptr<Incomplete>(new Incomplete(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));
			sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
		}
	}
	else if (time > 1410)
	{
		//push back function for trains that never left the station after 24 hours
		sim->neverLeftTheStationTrains(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay);
	}
}

// -- Processing Assembled Event
// -----------------------------------------
//	Sceduling Assembled event to ready
// ---------------------------------------- -
void Assembled::processEvent(shared_ptr<Simulation> &sim)
{
	state = "Ready";
	
	sim->scheduleEvent(shared_ptr<Ready>(new Ready(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));	
	sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
}
// -- Processing Ready Event
// -----------------------------------------
//	Checking if there is a delay, if yes, the distance between dep and des station need to be found
//  AvrageSpeed needs to be calculated. 
//  If the AvrageSpeeed is bigger or = max speed
//  Delay needs to be calculated with the new speed. if its less than 0. Delay time is set to 0
//  If tmpSpeed is less than 0 delay needs to be calculated
//  Delayed trains will be pushed into a vector hsred ptr
// -----------------------------------------

void Ready::processEvent(shared_ptr<Simulation> &sim)
{
	state = "Running";
	int tmpSpeed = 0;
	int NewDelayTime = 0;
	if (delay > 0)
	{
		//Finding distance
		int dist = sim->findDistance(departureStation, destinationStation);
		//Calc avgSpeed
		tmpSpeed = sim->calcAvgSpeed(sim->findMinutes(departureTime, destinationTime, delay), dist);
		
		if (tmpSpeed >= speed)
		{

			delay = sim->calcDelayTime(dist, speed, departureTime, destinationTime, delay); //Calc new delay time
			if (delay < 0)
			{
				delay = 0;
				
				sim->totalDelayTime(delay); //putting the delay time into a vector
			}
		}
		else if (tmpSpeed < 0)
		{
			delay = sim->calcDelayTime(dist, speed, departureTime, destinationTime, delay); //Calc new delay time
			sim->totalDelayTime(delay);//putting the delay time into a vector

		}
		
		sim->scheduleEvent(shared_ptr<Running>(new Running(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));
		sim->delayedTrains(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay);
		sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
	}
	else
	{
		
		int dist = sim->findDistance(departureStation, destinationStation);
		//Setting the speed of the train, so that it reaches the destination at the precise time
		speed = sim->calcAvgSpeed(sim->findMinutes(departureTime, destinationTime, delay), dist);

		sim->scheduleEvent(shared_ptr<Running>(new Running(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));
		sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
	}

}
// -- Processing Running Event
// -----------------------------------------
//	Sceduling Running event to Arrived
// -----------------------------------------
void Running::processEvent(shared_ptr<Simulation> &sim)
{
	state = "Arrived";
	sim->scheduleEvent(shared_ptr<Arrived>(new Arrived(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));
	sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
}

// -- Processing Arrived Event
// -----------------------------------------
//	Sceduling Arrived event to Finished
// ---------------------------------------- -
void Arrived::processEvent(shared_ptr<Simulation> &sim)
{
	state = "Finished";
	sim->scheduleEvent(shared_ptr<Finished>(new Finished(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay)));
	sim->carHistory(id, departureStation, destinationStation, departureTime, destinationTime, speed, time, Vint, VhistoryCar, delay, totalDelay,state);
}
// -- Processing Finished Event
// -----------------------------------------
//	Returning the Cars to its destination station
// ---------------------------------------- -
void Finished::processEvent(shared_ptr<Simulation> &sim)
{
	sim->ReturnCarsToStations(destinationStation, VhistoryCar);
}

// -- Nothing gets prossesed here
// -----------------------------------------
void NeverLeftTheStation::processEvent(shared_ptr<Simulation> &sim)
{}
void Delayed::processEvent(shared_ptr<Simulation> &sim)
{}
void TrainByCarId::processEvent(shared_ptr<Simulation> &sim)
{}
void CarHistory::processEvent(shared_ptr<Simulation> &sim)
{}
// -----------------------------------------
// -----------------------------------------


// -- Searching for a Car by Id in VhistoryCar in TrainByCarId class!
// -----------------------------------------
//	looping the VhistoryCar
//  If the arugment is equal getId() return true
// -----------------------------------------
bool TrainByCarId::searchForCarInVhistoryCar(int x)
{
	for (auto i = 0; i < VhistoryCar.size(); i++)
	{
		if (x == VhistoryCar[i]->getId())
		{
			return true;
		}
	}
	return false;
}
// -- Searching for a Car by Id in VhistoryCar in CarHistory class!
// -----------------------------------------
//	looping the VhistoryCar
//  If the arugment is equal getId() return true
// -----------------------------------------
bool CarHistory::searchForCarInVhistoryCar(int x)
{
	for (auto i = 0; i < VhistoryCar.size(); i++)
	{
		if (x == VhistoryCar[i]->getId())
		{
			return true;
		}
	}
	return false;
}

// -- converting int minutes to string clock
// -----------------------------------------
//	if minutes are less than 24h 00:00 
//  If minutes are more than 24h 00:00:00
// -----------------------------------------
string Event::minToClock(int pMin)
{
	stringstream ss;

	int hr = (pMin / 60) % 24;
	int min = pMin % 60;
	int day = (pMin / 60) / 24;

	if (pMin < 1440)
	{
		ss << setw(2) << setfill('0') << hr << ':'
			<< setw(2) << setfill('0') << min;
		return ss.str();
	}
	else
	{
		ss << setw(2) << setfill('0') << day << ':'
			<< setw(2) << setfill('0') << hr << ':'
			<< setw(2) << setfill('0') << min;
		return ss.str();
	}
}
// -- All the printing functions for the Event divered classes
// -----------------------------------------
//	Printing out infromation depending on log level low medium or high
// -----------------------------------------
void NotAssembled::printIncomplete()
{
	
	cout << endl << minToClock(time) << " Train[" << id << "](INCOMPLETE)" << endl
		<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
		<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
		<< "Speed = 0 km/h is now incomplete, next try at " << minToClock(time+Constants::incompleteTime) << endl;
}

void NotAssembled::printAssembled()
{
	cout << endl << minToClock(time) << " Train[" << id << "](ASSEMBLED)" << endl
		<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
		<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
		<< "Speed = 0 km/h is now assembled, arriving at the platform at " << minToClock(time + Constants::readyTime) << endl;

}

void NotAssembled::print(logLevel x)
{
	if (x == low)
	{
		if (Vint.empty())
		{
			printAssembled();
			for (auto &e : VhistoryCar)
			{
				e->print(low);
			}
		}
		else
		{
			printIncomplete();
			for (auto &e : VhistoryCar)
			{
				e->print(low);
			}
		}
	}
	if (x == medium)
	{

		if (Vint.empty())
		{
			printAssembled();

			for (auto &e : VhistoryCar)
			{
				e->print(medium);
			}
		}
		else
		{
			printIncomplete();
			for (auto &e : VhistoryCar)
			{
				e->print(medium);
			}
		}
	}
	if (x == high)
	{

		if (Vint.empty())
		{
			printAssembled();

			for (auto &e : VhistoryCar)
			{
				e->print(high);
			}
		}
		else
		{
			printIncomplete();
			for (auto &e : VhistoryCar)
			{
				e->print(high);
			}
		}
	}
}

void Incomplete::printIncomplete()
{
	
	cout << endl << minToClock(time) << " Train[" << id << "](INCOMPLETE)" << endl
		<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
		<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
		<< "Speed = 0 km/h is now incomplete, next try at " << minToClock(time + Constants::incompleteTime) << endl;
}

void Incomplete::printAssembled()
{
	cout << endl << minToClock(time) << " Train[" << id << "](ASSEMBLED)" << endl
		<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
		<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
		<< "Speed = 0 km/h is now assembled, arriving at the platform at " << minToClock(time + Constants::readyTime) << endl << endl;
}

void Incomplete::print(logLevel x)
{
	if (x == low)
	{
		if (Vint.empty())
		{

			printAssembled();
			for (auto &e : VhistoryCar)
			{
				e->print(low);
			}
		}
		else
		{
			printIncomplete();
		}
	}
	if (x == medium)
	{
		if (Vint.empty())
		{

			printAssembled();
			for (auto &e : VhistoryCar)
			{
				e->print(medium);
			}
		}
		else
		{
			printIncomplete();
		}
	}
	if (x == high)
	{
		if (Vint.empty())
		{

			printAssembled();
			for (auto &e : VhistoryCar)
			{
				e->print(high);
			}
		}
		else
		{
			printIncomplete();
		}
	}
}

void Assembled::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](READY)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = 0 km/h is now at the platform, departing at " << minToClock(time + Constants::runningTime) << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
	if (x == medium)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](READY)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = 0 km/h is now at the platform, departing at " << minToClock(time + Constants::runningTime) << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(medium);
		}
	}
	if (x == high)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](READY)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = 0 km/h is now at the platform, departing at " << minToClock(time + Constants::runningTime) << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(high);
		}
	}
}

void Ready::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](RUNNING)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " km/h has left the platform, traveling at speed " << speed << " (" << speed << ")" << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
	if (x == medium)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](RUNNING)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " km/h has left the platform, traveling at speed " << speed << " (" << speed << ")" << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(medium);
		}
	}
	if (x == high)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](RUNNING)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " km/h has left the platform, traveling at speed " << speed << " (" << speed << ")" << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(high);
		}
	}
}

void Running::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](ARRIVED)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + totalDelay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " km/h has arrived at the platform, disassembly at " << minToClock(time + Constants::disassembleTime) << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
	if (x == medium)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](ARRIVED)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + totalDelay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " km/h has arrived at the platform, disassembly at " << minToClock(time + Constants::disassembleTime) << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(medium);
		}
	}

	if (x == high)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](ARRIVED)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + totalDelay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " km/h has arrived at the platform, disassembly at " << minToClock(time + Constants::disassembleTime) << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(high);
		}
	}

}

void Arrived::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](FINISHED)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + totalDelay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " is now disassembled" << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
	if (x == medium)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](FINISHED)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + totalDelay) << ")"
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " is now disassembled" << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(medium);
		}
	}
	if (x == high)
	{
		cout << endl << minToClock(time) << " Train[" << id << "](FINISHED)" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Speed = " << speed << " is now disassembled" << endl << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(high);
		}
	}
}

void Finished::print(logLevel x)
{}

void NeverLeftTheStation::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << "------------------------" << endl;

		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

	}

	if (x == medium)
	{
		cout << endl << "------------------------" << endl;

		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Cars:" << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(medium);
		}
		cout << endl << "Missing vehicles" << endl;
		for (auto &e : Vint)
		{
			cout << e << endl;
		}
	}

	if (x == high)
	{
		cout << endl << "------------------------" << endl;

		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl
			<< "Cars:" << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(high);
		}
		cout << endl << "Missing vehicles" << endl;
		for (auto &e : Vint)
		{
			cout << e << endl;
		}
	}
}

void Delayed::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << "------------------------" << endl;
		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << endl;

	}
	if (x == medium)
	{
		cout << endl << "------------------------" << endl;
		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

	}
	if (x == high)
	{
		cout << endl << "------------------------" << endl;

		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
}

void TrainByCarId::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << "------------------------" << endl;
		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << endl;

	}
	if (x == medium)
	{
		cout << endl << "------------------------" << endl;
		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

	}
	if (x == high)
	{
		cout << endl << "------------------------" << endl;

		cout << endl << "Train[" << id << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
}

void CarHistory::print(logLevel x)
{
	if (x == low)
	{
		cout << endl << "------------------------" << endl;
		cout << endl << "Train[" << id << "] [" << state<< "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << endl;

	}
	if (x == medium)
	{
		cout << endl << "------------------------" << endl;
		cout << endl << "Train[" << id << "] [" << state << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

	}
	if (x == high)
	{
		cout << endl << "------------------------" << endl;

		cout << endl << "Train[" << id << "] [" << state << "]" << endl
			<< "From " << departureStation << " " << minToClock(departureTime) << "(" << minToClock(departureTime + delay) << ")" << endl
			<< "To " << destinationStation << " " << minToClock(destinationTime) << "(" << minToClock(destinationTime + delay) << ")" << " delay" << "(" << minToClock(delay) << ")" << endl;

		for (auto &e : VhistoryCar)
		{
			e->print(low);
		}
	}
}

// -----------------------------------------
// -----------------------------------------

