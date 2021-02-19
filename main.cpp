#include <iostream>
using std::cout;
using std::cin;
#include <string>
#include <cctype> //for toupper
using std::toupper;
using std::string;
#include <sstream> //for stringstream
using std::stringstream;

//THIS IS FOR CLEARING THE SCREEN
//IT MIGHT NOT WORK FOR YOUR IDE/OS
#include <stdlib.h>
using std::system; //for system("CLS"); which clears the console

#include "board.hpp"
#include "Tile.hpp"


//helper functions
bool isShipName(string name) {
	
	return ((name == "BATTLESHIP") || (name == "CARRIER") || (name == "CRUISER") || (name == "SUBMARINE") || (name == "DESTROYER"));
}

shipType nameToShipType(string name) {
	if (name == "BATTLESHIP")
		return battleship;
	if (name == "CARRIER")
		return carrier;
	if (name == "CRUISER")
		return cruiser;
	if (name == "SUBMARINE")
		return submarine;
	if (name == "DESTROYER")
		return destroyer;
	return noShip;
}

bool isDirection(string name) {
	return ((name == "UP") || (name == "RIGHT") || (name == "DOWN") || (name == "LEFT"));
}

direction nameToDirection(string name) {
	if (name == "UP")
		return up;
	if (name == "RIGHT")
		return right;
	if (name == "DOWN")
		return down;
	return left;
}

void promptClear() {
	cout << "PRESS ENTER TO CONTINUE\n";
	string temp;
	getline(cin, temp);
	system("CLS");
}

void placeSpecificShip(Board& board, shipType ship) {
	while (true) {
		//variables
		string input;
		stringstream sstream;
		direction dir;
		int xCoord;
		int yCoord;


		//loop that checks for valid xy coordinates
		board.printBoard();
		while (true) {
			cout << "\nWhere do you want to place the ship?\n";
			cout << "\nenter in form of \"x y\" where x and y are between 0 and 9 inclusive\n";
			getline(cin, input);


			sstream << input;
			sstream >> xCoord;
			sstream >> yCoord;
			sstream.clear();
			if (((xCoord >= 0) && (xCoord <= 9) && (yCoord >= 0) && (yCoord <= 9)))
				break;

		}

		system("CLS");
		cout << "x:" << xCoord << "\ty: " << yCoord << "\n";
		board.printBoard();
		

		//loop that checks for valid direction
		while (true) {
			cout << "\nWhat direction do you want to place the ship?\n";
			cout << "options are: up, down, left, right\n";
			getline(cin, input);
			for (char& c : input)
				c = toupper(c);
			dir = nameToDirection(input);
			if (isDirection(input))
				break;
		}

		//try catch block that tries to place the ship with the specified parameters onto the board
		//breaks from the outer loop if successful
		bool escapeFlag = true;
		try {
			board.placeShip(xCoord, yCoord, ship, dir);
		}
		catch (...) {
			cout << "invalid ship placement\n";
			escapeFlag = false;
		}
		if (escapeFlag)
			break;

	}
	system("CLS");
	cout << "\"successfully\" set ship\n\n";
	board.printBoard();
	promptClear();
}


void playerSetUP(Board& player) {
	cout << "Placing Carrier:\n";
	placeSpecificShip(player, carrier);
	cout << "Placing Battleship:\n";
	placeSpecificShip(player, battleship);
	cout << "Placing Cruiser:\n";
	placeSpecificShip(player, cruiser);
	cout << "Placing Submarine:\n";
	placeSpecificShip(player, submarine);
	cout << "Placing Destroyer:\n";
	placeSpecificShip(player, destroyer);
}




int main(){
    Board playerOneBoard;
    Board playerTwoBoard;
    cout << "Welcome to Battleship!\n"
         << "The rules are the following:\n"
         << "There is a 10x10 board. You will place "
         << "your 5 ships.\nThere are is a carrier, battleship "
         << "cruiser, submarine, and a destroyer.\nA destroyer is 2 "
         << "spots long, a submarine is 3, a cruiser and battleship "
         << "are 4,\nand a carrier is 5. You must sink your opponents "
         << "ships by hitting every spot they are in.\n";

    cout << "\nThe board will be laid out as such:\n";
    playerOneBoard.printBoard();

	cout << "\nEach spot is represented by a letter:\n"
		<< "W = Water / Unknown\n"
		<< "H = HIT! You hit a ship at that location.\n"
		<< "S = Shot. You've shot that location but nothing is there.\n"
		<< "A number represents a ship of that length\n"
		<< "note that both cruisers and battleships are represented with a 4\n";

    cout << "\nTo place your ships you will state the x and y\n"
         << "coordinates. x is horizontal and y is verticle.\n"
         << "This coordinate is the head of the ship. You will\n"
         << "also give the direction the ship is headed. This is\n"
         << "the direction the ship will span. Please note you\n"
         << "can't have overlapping ships and they can't go\n"
         << "out of bounds.\n";

    cout << "\nTo shoot, you will also state the x and y\n"
         << "coordinates. Please note you can't shoot any\n"
         << "spots you've already shot, whether it was a hit\n"
         << "or a miss.\n";

    cout << "\nLet's get started.\n";


	//new stuff
	//adds one valid ship to the board
	//outside while loop continues looping until place ship does not throw
	//the inner while loops go through each parameter (ie ship, x, y, direction) until a valid value is entered
	promptClear();
	cout << "Player 1 setup:\n";
	playerSetUP(playerOneBoard);
	cout << "Player 2 setup:\n";
	playerSetUP(playerTwoBoard);
	system("CLS");

	playerOneBoard.printBoard();
	cout << "\n\n";
	playerTwoBoard.printBoard();

	

 
    
    return 0;
}
