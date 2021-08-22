/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/
//----------------------------------------------
#include "TestApp.h"
//----------------------------------------------

int main()
{
	//Memory leak checker
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Creating the simulation
	shared_ptr<Simulation> sim(new Simulation);	
	
	shared_ptr<TestApp> ta(new TestApp);
	
	
	//Main run program
	ta->run(sim);

	return 0;
}