/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#ifndef CAR_H
#define CAR_H
//----------------------------------------------
#include <iostream>
using namespace std;
//----------------------------------------------
//Enum for logLevels
enum logLevel
{
	low, medium, high
};
//----------------------------------------------

class Car
{
protected:
	//parameters for derived classes
	int id;	
	int type;
	int param0;
	int param1;	

public:
	Car() {};
	virtual ~Car() {};	

	//pure virtual functions
	virtual int getId() const { return 0; }
	virtual int getType() const { return 0; }	
	virtual int getParam0() const { return 0; }
	virtual int getParam1() const { return 0; }

	virtual void print(logLevel x) = 0;

};
#endif
