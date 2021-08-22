/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef OPENFREIGHTCAR_H
#define OPENFREIGHTCAR_H
//----------------------------------------------
#include <iostream>
#include <string>
using namespace std;
//----------------------------------------------
#include "Car.h"
//----------------------------------------------


class OpenFreightCar : public Car
{
public:
	OpenFreightCar() {};
	OpenFreightCar(int pIdType, int pType, int pParam0, int pParam1);

	//Getters
	int getType() const { return type; }
	int getId() const { return id; }
	int getParam0() const { return param0; }
	int getParam1() const { return param1; }
	void print(logLevel x);
};

#endif

