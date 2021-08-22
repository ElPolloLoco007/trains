/**
* HT17 DT060G Datateknik GR (B), Objektorienterad programmering i C++
* Project: Trains
* Author: Helgi Poulsen helgipoulsen@hotmail.com
* 23-11-2017
* Version: 1.0
*/

//----------------------------------------------
#include"TestApp.h"
//----------------------------------------------



//------------------------------------------------------------------------
// ClearScreen
//------------------------------------------------------------------------
// Job: cleaning screen like system(CLS)
// Cleans screen with new empty lines
//------------------------------------------------------------------------
void clearscreen()
{
	//Clearing the screen with empty lines
	int n;
	for (n = 0; n < 10; n++)
		cout << ("\n\n\n\n\n\n\n\n\n\n");
}

//------------------------------------------------------------------------
// yesOrNo
//------------------------------------------------------------------------
// Job: Write out a question for the user so that the user presses yes or no
// to deside what the user want to do, then pressing enter. 
//------------------------------------------------------------------------
bool yesOrNo(string str)
{
	cout << endl;
	cout << str;
	char ch;
	do
	{
		cin >> ch; //asking for charater
		cin.get(); //pressing enter to continue
		ch = toupper(ch); //char to upper so caps or not dosent makes a difference
	} while (!(ch == 'Y' || ch == 'N'));
	return (ch == 'Y'); //return to top again in the function when used, do one more time
}

void returnToMenu()
{
	cout << endl<< "------------------------------" << endl;
	cout << "Press Enter to return to menu:";
	cin.get();
	cin.get();
	clearscreen();
}

void DWreturnToMenu()
{
	cout << endl << "------------------------------" << endl;
	cout << "Press Enter to return to menu:";	
	cin.get();
	clearscreen();
}

int inputNumbers(int x)
{
	cout << x;
	int option;
	//checking if its a integer that is pressed, and removing the wrongfully letter
	while (!(cin >> option))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;

		cout << "Invalid number!" << endl;
		cout << "Please enter a valid number from the list:";
	}
	
	cout << "----------------------" << endl;
	return option;
}