/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef SLEEPINGCAR_H
#define SLEEPINGCAR_H
//----------------------------------------------
#include <iostream>
#include <string>
using namespace std;
//----------------------------------------------
#include "Car.h"


class SleepingCar : public Car
{
public:
	SleepingCar() {};
	SleepingCar(int pIdType, int pType, int pParam0);

	//Getters
	int getType() const { return type; }
	int getId() const { return id; }
	int getParam0() const { return param0; }
	
	void print(logLevel x);
};

#endif
