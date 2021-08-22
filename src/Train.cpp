/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "Train.h"
//----------------------------------------------


Train::Train(int pId, string pDepartureStation, string pDestinationStation, int pDepartureTime, int pDestinationTime,int pSpeed, vector<int> pVcarTypes)
{
	id = pId;
	departureStation = pDepartureStation;
	destinationStation = pDestinationStation;
	departureTime = pDepartureTime;
	destinationTime = pDestinationTime;
	speed = pSpeed;	
	VcarTypes = pVcarTypes;
}

// --Print function of Train
// -----------------------------------------
//	Printing the train then looping through VcarTypes to print them aswell
// -----------------------------------------
void Train::print()
{
	cout << id << " " << departureStation << " " << destinationStation << " " << departureTime << " " << departureTime << " " << speed;
	
	for (auto &e : VcarTypes)
	{
		cout << e << " ";
	}


}

