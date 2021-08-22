/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "CoveredFrightCar.h"
//----------------------------------------------

CoveredFrightCar::CoveredFrightCar(int pId, int pType, int pCubicMeters)
{
	id = pId;
	type = pType;
	param0 = pCubicMeters;
}

void CoveredFrightCar::print(logLevel x)
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
		cout << "Cargo capacity in cubic meters:" << param0 << endl;
	}

	if (x == high)
	{
		cout << "-----------CAR with ID:" << id << "-----------" << endl;
		cout << "Type:" << type << endl;
		cout << "Cargo capacity in cubic meters:" << param0 << endl;
	}
}