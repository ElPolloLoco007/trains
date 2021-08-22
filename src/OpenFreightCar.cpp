/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "OpenFreightCar.h"



OpenFreightCar::OpenFreightCar(int pId, int pType, int pTons, int pSquareMeters)
{
	id = pId;
	type = pType;
	param0 = pTons;
	param1 = pSquareMeters;
}

void OpenFreightCar::print(logLevel x)
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
		cout << "Cargo Capacity in tons:" << param0 << endl;		
	}


	if (x == high)
	{
		cout << "-----------CAR with ID:" << id << "-----------" << endl;
		cout << "Type:" << type << endl;
		cout << "Cargo Capacity in tons:" << param0 << endl;
		cout << "Floor area in square meters:" << param1 << endl;		
	}
}
