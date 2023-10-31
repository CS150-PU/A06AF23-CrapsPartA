//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        10/31/2023
// Class:       CS150-xx (xx is your section number)
// Assignment:  06 Craps Part A
// Purpose:     
// Hours:       
//******************************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

const int HOUSE_BANK = 10000;

// Craps Part A function prototypes
void drawHeading (string title, char borderChar);
int getPlayerBuyin (string prompt, int houseBank);
int getPlayerBet (string prompt, int playerChips);
void drawDieFace (int face); 
void drawDiceFace (int face1, int face2);
int rollDie ();
int rollDice (int &dieOne, int &dieTwo);

/***********************************************************************
Function:			main

Description:	Driver for Craps game (Part A)

Parameters:		None

Returned:			exit status
***********************************************************************/

/******************  DO NOT CHANGE MAIN !!!!!!!!!  ********************/
int main () {

	const string GAME_TITLE = "Let's Play Craps",
		           BUY_IN_PROMPT = "Enter Player Buy-In: $",
		           BET_PROMPT = "Enter Player Bet: ";
	const char BORDER_CHARACTER = '*';

	int houseMoney = HOUSE_BANK,
		  playerChips,
		  playerBet,
		  dieOne, dieTwo;

  // srand (static_cast <unsigned> (time (static_cast <time_t*> (NULL))));
	srand (4); // creates the same pseudo-random sequence
						 // 0 is (2, 5) on first roll, 4 is a (2, 6) on first roll

	drawHeading (GAME_TITLE, BORDER_CHARACTER);
	cout << endl;

	playerChips = getPlayerBuyin (BUY_IN_PROMPT, HOUSE_BANK);
	cout << endl;

	drawHeading (GAME_TITLE, BORDER_CHARACTER);
	cout << endl;

	cout << "House Bank: $" << houseMoney + playerChips << endl;
	cout << "Player Chips: " << playerChips << endl << endl;

	playerBet = getPlayerBet (BET_PROMPT, playerChips);
	cout << endl;

	drawHeading (GAME_TITLE, BORDER_CHARACTER);
	cout << endl;

	rollDice (dieOne, dieTwo);
	drawDiceFace (dieOne, dieTwo);

  return EXIT_SUCCESS;
}