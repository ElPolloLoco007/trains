/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef TESTAPP_H
#define TESTAPP_H
//----------------------------------------------
//Included libraries
#include <iostream>
#include <iomanip>
#include <string>		
#include <vector>
#include <memory>
#include <fstream>
using namespace std;
//----------------------------------------------
#include "Simulation.h"
#include "Event.h"
//----------------------------------------------
						
class TestApp
{
private:
	int MenuOption;	//Doing menu options

public:
	TestApp();

	//Running the main program
	void run(shared_ptr<Simulation> &pSim);

	//Menus
	void startSimulation(shared_ptr<Simulation> &pSim);	
	void TrainMenu(shared_ptr<Simulation> &pSim);
	void StationMenu(shared_ptr<Simulation> &pSim);
	void CarMenu(shared_ptr<Simulation> &pSim);

	//Changing log level
	void changeLogLevel(shared_ptr<Simulation> &pSim);

	//Setters
	void setSimStartTime(shared_ptr<Simulation> &pSim);
	void setSimEndTime(shared_ptr<Simulation> &pSim);
	void setInterval(shared_ptr<Simulation> &pSim);
	bool setLogLevel(shared_ptr<Simulation> &pSim, int x);

	
	//menu functions
	//----------------------------------
	int getMenuOption() { return MenuOption; };
	//returning MenuOption

	int doMenuOption(int option);
	/* Pre:   Checking if a integer has been typed in
	Post:  setting the typed in int to MenuOption;  */
	//----------------------------------

};

void clearscreen();
/* Pre:   -
Post:  Cleaning the screen */

#endif
