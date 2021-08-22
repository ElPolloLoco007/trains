/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "TrainMap.h"
//----------------------------------------------


TrainMap::TrainMap(string pStation1, string pStation2, int pDistance)
{
	station1 = pStation1;
	station2 = pStation2;
	distance = pDistance;
}


TrainMap::~TrainMap()
{}


