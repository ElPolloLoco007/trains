/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "SleepingCar.h"
//----------------------------------------------

SleepingCar::SleepingCar(int pId, int pType, int pnumberOfBeds)
{
	id = pId;
	type = pType;
	param0 = pnumberOfBeds;	
}

void SleepingCar::print(logLevel x)
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
		cout << "Number of beds:" << param0 << endl;		
	}

	if (x == high)
	{
		cout << "-----------CAR with ID:" << id << "-----------" << endl;
		cout << "Type:" << type << endl;
		cout << "Number of beds:" << param0 << endl;		
	}
}