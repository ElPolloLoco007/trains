/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef TRAINMAP_H
#define TRAINMAP_H
//----------------------------------------------
#include <iostream>
#include <vector>
#include <string>
//----------------------------------------------
#include "Car.h"
//----------------------------------------------

class TrainMap
{
private:
	string station1;
	string station2;
	int distance;

public:
	TrainMap() {};
	TrainMap(string pStation1, string pStation2, int pDistance);
	~TrainMap();

	//Getters
	string getStation1() const { return station1; };
	string getStation2() const { return station2; };
	int getDistance() const { return distance; };

	

	
};
#endif


