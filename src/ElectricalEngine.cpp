/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "ElectricalEngine.h"
//----------------------------------------------

ElectricalEngine::ElectricalEngine(int pId, int pType, int pMSpeed, int pPowerkW)
{
	id = pId;
	type = pType;
	param0 = pMSpeed;
	param1 = pPowerkW;
}

void ElectricalEngine::print(logLevel x)
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
		cout << "Power kW:" << param1 << endl;
	}
}
