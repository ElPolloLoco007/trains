/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "Caoch.h"
//----------------------------------------------

Caoch::Caoch(int pId, int pType, int pNumberOfChairs, int pInternet)
{
	id = pId;
	type = pType;
	param0 = pNumberOfChairs;
	param1 = pInternet;
}

void Caoch::print(logLevel x)
{
	//logLevel
	if (x == low)
	{
		cout << "-----------CAR with ID:"<< id <<"-----------" << endl;		
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
		cout << "Internet yes/no:" << param1 << endl;		
	}
}