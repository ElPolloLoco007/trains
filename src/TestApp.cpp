/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "TestApp.h"
//----------------------------------------------


TestApp::TestApp()
{}

// --Run
// -----------------------------------------
//	Main run program
// -----------------------------------------
void TestApp::run(shared_ptr<Simulation> &pSim)
{	
	//For starting the simulation
	pSim = make_shared<Simulation>();
	pSim->readFiles();

	clearscreen();

	bool again = true;
	do
	{		
		
		int pStartTime = pSim->getSimStartTime();
		int pEndTime = pSim->getSimEndTime();
		cout << "**** Trains ****" << endl;
		cout << "1.Change start time " << pSim->convertIntMinToString(pStartTime) << endl;
		cout << "2.Change end time " << pSim->convertIntMinToString(pEndTime) << endl;
		cout << "3.Start simulation" << endl;
		cout << "4.Reset simulation" << endl;
		cout << "0.Exit" << endl;

		
		doMenuOption(MenuOption);			// Setting the menu choice from the user
		switch (getMenuOption())   // Getting the menu choice that the user has picked
		{
			// Run the selected function
		case 1:setSimStartTime(pSim);
			clearscreen();
			break;
		case 2: setSimEndTime(pSim);
			clearscreen();
			break;
		case 3: startSimulation(pSim);
			clearscreen();
			break;
		case 4: pSim = make_shared<Simulation>(); pSim->readFiles(); //Resetting simulation
			clearscreen();
			break;
		

		case 0: again = false;
		}
	} while (again);
}
//------------------------------------------------------------------------

// --Start Simulation
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::startSimulation(shared_ptr<Simulation> &pSim)
{
		
	clearscreen();

	bool again = true;
	do
	{
		int pInterval = pSim->getInterval();
		cout << "**** Start simulation ****" << endl;
		cout << "1.Change interval " << pSim->convertIntMinToString(pInterval) << endl;
		cout << "2.Run next interval" << endl;
		cout << "3.Next event" << endl;
		cout << "4.Finish (Complete simulation)" << endl;
		cout << "5.Change log level"<< pSim->convertLogLevelToString(pSim->getLogLevel()) << endl;
		cout << "6.Print statistics" << endl;
		cout << "7.Train menu" << endl;
		cout << "8.Station menu" << endl;
		cout << "9.Vehicle menu" << endl;
		cout << "0.Return" << endl;

		doMenuOption(MenuOption);			// Setting the menu choice from the user
		switch (getMenuOption())   // Getting the menu choice that the user has picked
		{
			// Run the selected function
		case 1:setInterval(pSim);
			clearscreen();
			break;
		case 2: pSim->runNextInterval(pSim);			
			clearscreen();
			break;
		case 3: pSim->nextEvent(pSim); 			
			clearscreen();
			break;
		case 4: pSim->finished(pSim); 			
			clearscreen();
			break;
		case 5: changeLogLevel(pSim);
			clearscreen();
			break;
		case 6: pSim->statistics(pSim);			
			clearscreen();
			break;
		case 7: TrainMenu(pSim);
			clearscreen();
			break;
		case 8: StationMenu(pSim);
			clearscreen();
			break;
		case 9: CarMenu(pSim);
			clearscreen();
		case 0: again = false;
		}
	} while (again);
}

// --Train menu
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::TrainMenu(shared_ptr<Simulation> &pSim)
{	

	bool again = true;
	do
	{
		int pInterval = pSim->getInterval();
		cout << "**** Train Menu ****" << endl;
		cout << "1.Search train by number"<< endl;
		cout << "2.Search train by Car id" << endl;
		cout << "3.Show all trains" << endl;		
		cout << "4.Change log level" << pSim->convertLogLevelToString(pSim->getLogLevel()) << endl;		
		cout << "0.Return" << endl;

		doMenuOption(MenuOption);			// Setting the menu choice from the user
		switch (getMenuOption())   // Getting the menu choice that the user has picked
		{
			// Run the selected function
		case 1:pSim->searchTrainByNumber();
			clearscreen();
			break;
		case 2:pSim->findTrainByCar();
			clearscreen();
			break;
		case 3: pSim->showAllTrains();
			clearscreen();
			break;
		case 4:changeLogLevel(pSim);
			clearscreen();
			break;		
		case 0: again = false;
		}
	} while (again);
}
// --Station menu
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::StationMenu(shared_ptr<Simulation> &pSim)
{
	bool again = true;
	do
	{
		int pInterval = pSim->getInterval();
		cout << "**** Station Menu ****" << endl;
		cout << "1.Show station names" << endl;
		cout << "2.Show station by name" << endl;
		cout << "3.Show all stations" << endl;
		cout << "4.Change log level" << pSim->convertLogLevelToString(pSim->getLogLevel()) << endl;
		cout << "0.Return" << endl;

		doMenuOption(MenuOption);			// Setting the menu choice from the user
		switch (getMenuOption())   // Getting the menu choice that the user has picked
		{
			// Run the selected function
		case 1:pSim->ShowStationNames();
			clearscreen();
			break;
		case 2:pSim->ShowStationByName();
			clearscreen();
			break;
		case 3: pSim->ShowAllStationsAndCars();
			clearscreen();
			break;
		case 4:changeLogLevel(pSim);
			clearscreen();
			break;
		case 0: again = false;
		}
	} while (again);
}

// --Car menu
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::CarMenu(shared_ptr<Simulation> &pSim)
{

	bool again = true;
	do
	{
		int pInterval = pSim->getInterval();
		cout << "**** Vehicle menu ****" << endl;
		cout << "1.Search vehicle by id" << endl;
		cout << "2.Show all vehicles" << endl;		
		cout << "3.History of vehicle at the given time" << endl;
		cout << "4.Change log level" << pSim->convertLogLevelToString(pSim->getLogLevel()) << endl;
		cout << "0.Return" << endl;

		doMenuOption(MenuOption);			// Setting the menu choice from the user
		switch (getMenuOption())   // Getting the menu choice that the user has picked
		{
			// Run the selected function
		case 1:pSim->findCarById();
			clearscreen();
			break;
		case 2:pSim->AllCars();
			clearscreen();
			break;
		case 3:pSim->showHistoryOfCar();
			clearscreen();
			break;
		case 4:changeLogLevel(pSim); 
			clearscreen();
			break;
		case 0: again = false;
		}
	} while (again);
}


// --Log level menu 
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::changeLogLevel(shared_ptr<Simulation> &pSim)
{
	clearscreen();

	bool again = true;
	do
	{		
		cout << "**** Log level menu ****" << endl;
		cout << "Current Log level: "<< pSim->convertLogLevelToString(pSim->getLogLevel()) << endl;
		cout << "1.Low log level " << endl;
		cout << "2.Medium log level" << endl;
		cout << "3.High log level" << endl;		
		cout << "0.Return" << endl;

		doMenuOption(MenuOption);			// Setting the menu choice from the user
		switch (getMenuOption())   // Getting the menu choice that the user has picked
		{
			// Run the selected function
		case 1:setLogLevel(pSim, MenuOption);
			clearscreen();
			break;
		case 2:setLogLevel(pSim, MenuOption);
			clearscreen();
			break;
		case 3: setLogLevel(pSim, MenuOption);
			clearscreen();
			break;		
		case 0: again = false;
		}
	} while (again);
}



// --Setting log level
// -----------------------------------------
//	Sub menu
// -----------------------------------------
bool TestApp::setLogLevel(shared_ptr<Simulation>  &pSim, int x)
{
	if(x == 1)
	{
		pSim->setLogLevel(low);
		return true;
	}
	else if (x == 2)
	{
		pSim->setLogLevel(medium);
		return true;
	}
	else if (x == 3)
	{
		pSim->setLogLevel(high);
		return true;
	}
	else
	{
		cout << "Wrong input, try again" << endl;
		return false;
	}
}




// --Setting SimStartTime
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::setSimStartTime(shared_ptr<Simulation> &pSim)
{
	string input;
	string sTime = "00:"; //for days. the user is only limited to do 24h even though the program can run longer

	cout << "example:06:10" << endl;
	cout << "Change start time:";
	cin.get();
	getline(cin, input);
	input = sTime + input;

	pSim->setSimStartTime(input);
}

// --Setting simEndTime
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::setSimEndTime(shared_ptr<Simulation> &pSim)
{
	string input;
	string sTime = "00:"; //for days. the user is only limited to do 24h even though the program can run longer

	cout << "example:23:10" << endl;
	cout << "Change End time:";
	cin.get();
	getline(cin, input);
	input = sTime + input;

	pSim->setSimEndTime(input);
}

// --Setting interval
// -----------------------------------------
//	Sub menu
// -----------------------------------------
void TestApp::setInterval(shared_ptr<Simulation> &pSim)
{
	string input;	
	string sTime = "00:";//for days. the user is only limited to do 24h even though the program can run longer

	cout << "example: 00:20" << endl;
	cout << "Change end time:";
	cin.get();
	getline(cin, input);
	input = sTime+input;
	
	pSim->setInterval(input);
}


/* Pre:   Checking if a integer has been typed in
Post:  setting the typed in int to MenuOption;  */
int TestApp::doMenuOption(int option)
{
	cout << endl << "Make your option:";

	//checking if its a integer that is pressed, and removing the wrongfully letter
	while (!(cin >> option))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;

		//reporting that the user has used wrong input
		cout << "Invalid number!" << endl;
		cout << "Please enter a valid number from the list:";
	}
	//setting menuchoice to x
	MenuOption = option;
	return MenuOption;
	cout << "----------------------" << endl;
}