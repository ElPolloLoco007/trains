/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "Station.h"
//----------------------------------------------


Station::Station(string pStationName)
{
	stationName = pStationName;
	vector<unique_ptr<Car>> Vcar;
	
}

Station::~Station()
{}


// -- push back car
// -----------------------------------------
//	pushing back objects depending on what type it is to Vcar
//  sorting the Vcar vector after by id
// -----------------------------------------
void Station::pushBackCar(int pid, int ptype, int pparam0, int pparam1)
{	
	//Pushing back depending on type
	if (ptype == 0)
	{
		Vcar.push_back(shared_ptr<Caoch>(new Caoch(pid, ptype, pparam0, pparam1)));
		
	}

	else if (ptype == 1)
	{
		Vcar.push_back(shared_ptr<SleepingCar>(new SleepingCar(pid, ptype, pparam0)));
		
	}

	else if (ptype == 2)
	{
		Vcar.push_back(shared_ptr<OpenFreightCar>(new OpenFreightCar(pid, ptype, pparam0, pparam1)));
		
	}
	else if (ptype == 3)
	{
		Vcar.push_back(shared_ptr<CoveredFrightCar>(new CoveredFrightCar(pid, ptype, pparam0)));
		
	}
	else if (ptype == 4)
	{
		Vcar.push_back(shared_ptr<ElectricalEngine>(new ElectricalEngine(pid, ptype, pparam0, pparam1)));
		
	}
	else if (ptype == 5)
	{
		Vcar.push_back(shared_ptr<DieselEngine>(new DieselEngine(pid, ptype, pparam0, pparam1)));		
	}

	//sorting Vcar by Id
	sort(Vcar.begin(), Vcar.end(), [](shared_ptr<Car> &lhs, shared_ptr<Car> &rhs)
	{		
		
			return lhs->getId() < rhs->getId();
	});

}


// -- Search for car by id
// -----------------------------------------
//	looping Vcar if arguments matches a id
//  print hte object and return true
// -----------------------------------------
bool Station::searchForCarById(logLevel x,int tmp)
{	
	for (auto &e : Vcar)
	{
		if (e->getId() == tmp)
		{			
			e->print(x);
			return true;
		}
	}
	return false;
}

// -- Search for car in station
// -----------------------------------------
//	looping Vcar to check if a station name and carType matches
//  if yes setting index to e
//  Then erasing e from Vcar but returning index
//  Simulation of train getting a car from the station so now the car belongs to the train
// -----------------------------------------
shared_ptr<Car> Station::searchforcar(string pStation, int tmp)
{
	int x = 0;
	shared_ptr<Car> index;
	for (auto &e : Vcar)
	{
		if (stationName == pStation  && e->getType() == tmp)
		{
			index = e;
			Vcar.erase(Vcar.begin() + x);
			return index;
		}
		x++;
	}
	return nullptr;
}

// --getCars
// -----------------------------------------
//	Printing out all cars in Vcar
// -----------------------------------------
void Station::getCars(logLevel x)
{	
	for (auto &e : Vcar)
	{			
		e->print(x);
	}	
}

// --Getting the size of Vcar
// -----------------------------------------
//	returning size of Vector
// -----------------------------------------
int Station::VcarSize()
{
	return Vcar.size();
}