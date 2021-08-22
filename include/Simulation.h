/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef SIMULATION_H
#define SIMULATION_H
//----------------------------------------------
#include <queue>
#include <vector>
#include <exception>
#include <stdexcept>

#include "Event.h"
 
//----------------------------------------------

class Simulation
{
private:
	string inputStartTime;
	string inputEndTime;
	int currentTime;
	int interval = 10;    //00:10
	int simStartTime = 0; //00:00
	int simEndTime = 1439;  //23:59

	//starting loglLevel
	logLevel ll = low;

	//The eventQueue for the simulation
	priority_queue<shared_ptr<Event>, vector<shared_ptr<Event>>, EventComparison> eventQueue;
	
	//Vectors to read the files
	vector<shared_ptr<Train>> Vtrain;
	vector<shared_ptr<Station>> Vstation;	
	vector<shared_ptr<TrainMap>> VtrainMap;

	//copying
	vector<shared_ptr<Station>> VcopyStation;
	vector<shared_ptr<Train>> VcopyTrain;

	//Vectors to catch the trains that never left the station and got delayed
	vector<shared_ptr<NeverLeftTheStation>> Vnlts;
	vector<shared_ptr<Delayed>> Vdelayed;
	vector<shared_ptr<TrainByCarId>> VtrainByCarId;
	vector<shared_ptr<CarHistory>> Vch; //CarHistory

	//Vector that takes all the delay time of all the trains
	vector<int> VtotalDelayTime;

	//storing the types when reading the Train file
	vector<int> typeStorage;
	
	
public:
	Simulation() = default;	
	
	
	void moveTrainVectorToQueue();
	/* Pre: Checking if Vtrain vector is empty
	Post:  Push into derived class Not Assembled with the popVector(); */

	void scheduleEvent(shared_ptr<Event> pNewEvent); //Push the event from eventQueue
	
	void statistics(shared_ptr<Simulation> &sim);
	/* Pre: -
	Post:  Finding statistics of Cars in the train stations at the beginning at the simulation.
	Finding the delayed trains at the end of simulation
	Finding the trains that never left the station at the end of the simulation*/

	bool runNextInterval(shared_ptr<Simulation> &sim);
	/* Pre: checking if the eventQueue is not empty and currentTime is < than simEndTime
	Post:  Running the sim until simStartTime then only printing out the intervals; */

	void nextEvent(shared_ptr<Simulation> &sim);
	/* Pre: checking if the eventQueue is not empty and currentTime is < than simStartTime
	Post:  Running only 1 event until simEndTime; */

	void finished(shared_ptr<Simulation> &sim);
	/* Pre: checking if the eventQueue is not empty
	Post:  Running all the sim; */

	
	//----------------------------------------------
	//Reading the files
	void readTrainsFile();
	void readTrainStationFile();
	void readTrainMapFile();

	//Reading all the files and moving TrainVector to queue
	void readFiles();
	//----------------------------------------------	

	bool isEmpty();  //Checking if Vtrain is empty	
	shared_ptr<Train> popVector(); //Setting a tmp Shared_ptr to train.back(), then popping Vtrain.back() and returning tmp

	//----------------------------------------------
	//Getters 	
	int getTime() const { return currentTime; }
	int getInterval() const { return interval; }
	int getSimStartTime() const { return simStartTime; }
	int getSimEndTime() const { return simEndTime; }
	logLevel getLogLevel() const { return ll; }

	//Setters
	bool setSimStartTime(string pSimStartTime);
	bool setSimEndTime(string pSimEndTime);
	bool setInterval(string pInterval);
	bool setLogLevel(logLevel pLl);
	//----------------------------------------------
	
	//Finding(locating) functions
	shared_ptr<Car> findCarTypeInStation(string pStation, int pCarType);
	int findSpeed(vector <shared_ptr<Car>> pCar);
	int findDistance(string pDepartureStation, string pDestinationStation);
	int findMinutes(int pdeptime, int pdestime, int pdelay);
	//----------------------------------------------
	//Calculating functions
	int calcAvgSpeed(int pDistance, int pMin);  //Calculationg avrage speed by using distance and time(min)
	int calcDelayTime(int pdistance, int pspeed, int departureTime, int destinationTime, int delay);  //Calculating the NEW delayed time of the train with train max speed	
	//----------------------------------------------
	
	//Returning the cars to station after the train has reached its destination
	void ReturnCarsToStations(string pStation, vector <shared_ptr<Car>> pCar);	
	//----------------------------------------------
	
	//Pushing back into vectors the trains that never left the station and that got delayed and total delayed time
	void neverLeftTheStationTrains(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	void delayedTrains(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	void searchTrainByCarId(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay);
	void carHistory(int pid, string pdepartureStation, string pdestinationStation, int pdepartureTime, int pdestinationTime, int pspeed, int ptime, vector <int> pVint, vector<shared_ptr<Car>> VhistoryCar, int pDelay, int ptotalDelay, string pState);
	void totalDelayTime(int x); //Calculating the total delayed time
	//----------------------------------------------
	
	//Converters
	string convertIntMinToString(int pMin);  //Minutes to string time 20 min = 00:20
	string convertLogLevelToString(int pMin);  //Converting log level to string 0 = low
	int convertInputTimeToMin(string Time);  //String to minutes // 00:20 to 20
	//----------------------------------------------		
	void copyVectorVstation();//Copying the Vstation vector to VcopyStation
	void copyVectorVtrain(); //Copying the Vtrain vector to VcopyStation
	//----------------------------------------------
	bool searchTrainByNumber();  //Searchign train by Id
	void findTrainByCar();		// Finding train by carId
	bool showAllTrains();        //Showing all trains
	//----------------------------------------------
	void ShowStationNames(); //Show station names
	bool ShowStationByName(); //Searching for station
	void ShowAllStationsAndCars(); //Showing all stations
	//----------------------------------------------
	void findCarById(); //Searching for car by id
	void AllCars(); //Show all cars
	void showHistoryOfCar();  //Showign the history of a Car

};

bool yesOrNo(string str);  //Yes or no option
void clearscreen(); //Cleaning the screen
void returnToMenu(); //Printing text and making the user press a key before returning to menu
void DWreturnToMenu(); //Printing text and making the user press a key before returning to menu (For functions with do) 

#endif
