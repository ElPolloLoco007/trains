/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "DieselEngine.h"
//----------------------------------------------


DieselEngine::DieselEngine(int pId, int pType, int pMSpeed, int pFuel)
{
	id = pId;
	type = pType;
	param0 = pMSpeed;
	param1 = pFuel;
}

void DieselEngine::print(logLevel x)
{	
	//Desiding logLevel
	if (x == low)
	{
		cout << "-----------CAR with ID:" << id << "-----------" << endl;
		cout << "Type:" << type << endl;
	}

	if (x == medium)
	{
		cout << "-----------CAR with ID:" << id << "-----------" << endl;
		cout << "Type:" << type << endl;
		cout << "Max speed in km/h:" << param0 << endl;
	}

	if (x == high)
	{
		cout << "-----------CAR with ID:" << id << "-----------" << endl;
		cout << "Type:" << type << endl;
		cout << "Max speed in km/h:" << param0 << endl;
		cout << "Fuel consumption in liters/h:" << param1 << endl;
	}
}
