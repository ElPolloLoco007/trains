/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef EVENT_H
#define EVENT_H
//----------------------------------------------
#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
//----------------------------------------------
#include "Train.h"
#include "Station.h"
#include "TrainMap.h"
#include "Constants.h"
//----------------------------------------------
// Forward declarations
class Simulation;
//----------------------------------------------

class Event
{	
protected:
	
	int time; // Time for this event
	int id;
	string departureStation;
	string destinationStation;
	int departureTime;
	int destinationTime;
	int speed;
	int delay;
	int totalDelay;
	int distance;
	vector <int> Vint; //original Car vector
	vector<shared_ptr<Car>> VhistoryCar; //History of the cars in the tain, since they need to be returned to the station and Vint will be pop.back()	

	string state; //Incomplete assembled etc...

public:
	// Constructor requires time of event
	Event() = default;
	virtual ~Event() {}

	// Process event by invoking this method
	virtual void processEvent(shared_ptr<Simulation> &sim) = 0;

	//printing
	virtual void print(logLevel x) = 0;	

	// Getters
	int getTime() const {return time; } //Time for event	
	
	//Converting int minutes to string for cout
	string minToClock(int pMin);		
};


//-------------------------------------------------------
// Used to compare to Events with respect to time
class EventComparison  {
public:
	bool operator() (const shared_ptr<Event> & left, const shared_ptr<Event> & right)
	{
		return left->getTime() > right->getTime();
	}
};

//-------------------------------------------------------
//Derived Event classes
//-------------------------------------------------------

//Starting point for all the trains that are moved to the eventQueue
class NotAssembled : public Event {
public:
	NotAssembled(shared_ptr<Train> tmp);

	//Processing the NotAssembled event to either Assembled or Incomplete
	virtual void processEvent(shared_ptr<Simulation> &sim) override;

	void printAssembled();  //For saving copy pase code
	void printIncomplete();	//For saving copy pase code
	void print(logLevel x);
	
};
//-------------------------------------------------------

class Incomplete : public Event {
public:
	Incomplete(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);

	//Processing the Incomplete event to either Assembled or Incomplete again with 10 min delay
	virtual void processEvent(shared_ptr<Simulation> &sim) override;

	void printAssembled();
	void printIncomplete();
	void print(logLevel x);
	
};
//-------------------------------------------------------

class Assembled : public Event {
public:
	Assembled(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//Processing the Assembled event to Ready
	virtual void processEvent(shared_ptr<Simulation> &sim) override;	
	void print(logLevel x);
	
};
//-------------------------------------------------------

class Ready : public Event {
public:
	Ready(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//Processing the Ready event to Running
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);
	

};
//-------------------------------------------------------

class Running : public Event {
public:
	Running(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//Processing Running event to Arrived 
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);
	

};
//-------------------------------------------------------

class Arrived : public Event {
public:
	Arrived(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//Processing the Arrived event to finish
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);
	

};
//-------------------------------------------------------
class Finished : public Event {
public:
	Finished(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//Processing Finished event by returning cars to their destination station
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);
	
};
//-------------------------------------------------------


// DeEvent classes that are not implemented in the event chain
// I created these so that if I wanted to suddently implement on of these classes in the even chain it would be easy
//-------------------------------------------------------

//Delayed for finding all the delayed trains
//Can be implemented in the Event chain
//-------------------------------------------------------
class Delayed : public Event {
public:
	Delayed(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//No processing
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);

};
//For finding all the trains that never left the station
//Can be implemented in the Event chain
//-------------------------------------------------------
class NeverLeftTheStation : public Event {
public:
	NeverLeftTheStation(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//No processing
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);

};
//For finding Train by car id.
//Can be implemented in the Event chain
//-------------------------------------------------------
class TrainByCarId : public Event {
public:
	TrainByCarId(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	
	//No processing
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);
	
	bool searchForCarInVhistoryCar(int x);
	/* Pre: -
	Post:  looping the vector VhistoryCar to check if the argument x matches
			getId(), if yes return true*/

};
//For finding the history of a Car
//Can be implemented in the Event chain
class CarHistory : public Event {
public:
	CarHistory(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay,string pState);
	
	//No processing
	virtual void processEvent(shared_ptr<Simulation> &sim) override;
	void print(logLevel x);
		
	bool searchForCarInVhistoryCar(int x);
	/* Pre: -
	Post:  looping the vector VhistoryCar to check if the argument x matches
	getId(), if yes return true*/
};
#endif
