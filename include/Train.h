/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef TRAIN_H
#define TRAIN_H
//----------------------------------------------
#include <iostream>
#include <vector>
#include <string>
//----------------------------------------------
#include "Car.h"
//----------------------------------------------

class Train
{
private:
	int id;
	string departureStation;
	string destinationStation;
	int departureTime;
	int destinationTime;
	int speed;

	//For the Cars types
	vector<int> VcarTypes;	
	
public:
	Train() {};
	Train(int pId, string pDepartureStation, string pDestinationStation, int pDepartureTime, int pDestinationTime, int pSpeed, vector<int> pVcarTypes);


	//Getters
	int getId() const { return id; };
	string getDepartureStation() const { return departureStation; };
	string getDestinationStation() const { return destinationStation; };
	int getDepartureTime() const { return departureTime; };
	int getDestinationTime() const { return destinationTime; };
	int getSpeed() const { return speed; };
	vector <int> getVcarTypes() const { return VcarTypes; };
	
	void print();
};
#endif

