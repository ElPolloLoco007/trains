/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef STATION_H
#define STATION_H
//----------------------------------------------
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
//----------------------------------------------
#include "Car.h"
#include "Caoch.h"
#include "SleepingCar.h"
#include "CoveredFrightCar.h"
#include "OpenFreightCar.h"
#include "ElectricalEngine.h"
#include "DieselEngine.h"
//----------------------------------------------

class Station
{
private:
	string stationName;

	//Vector to stor all the cars
	vector<shared_ptr<Car>> Vcar;	

public:
	Station() {};
	Station(string pStationName);
	~Station();
	
	//Getter
	string getStationName() const { return stationName; };

	int VcarSize(); //Finding the size of vector Vcar
	
	shared_ptr<Car> searchforcar(string pStation, int tmp);	
	/* Pre: -
	Post:  For finding a car type in station, if found, returning the shared_ptr of that car
		   and then deleting it from the station*/

	//Searchign and printing cars
	bool searchForCarById(logLevel x, int tmp);
	void getCars(logLevel x);
	
	//Pushing back car into the right vector class
	void pushBackCar(int pid, int ptype, int pparam0, int pparam1);

};


#endif
