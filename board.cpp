//Jacob Jakiemiec
//Kelby Hubbard
//board.cpp

#include "board.hpp"
#include <exception>
#include <iostream>

//helper functions
bool Board::isValidPlacement(int x, int y, direction dir, shipType type) {
	switch (dir) {
	case up:
		return isValidUpPlacement(x, y, type);
	case right:
		return isValidRightPlacement(x, y, type);
	case down:
		return isValidDownPlacement(x, y, type);
	case left:
		return isValidLeftPlacement(x, y, type);
	default:
		return false;
	}
}


bool Board::isValidUpPlacement(int x, int y, shipType type) {
	if (y + type > 9)
		return false;
	for (int i = 0; i < type; i++)
		if (doesIndexExist(x, y + i) == true)
			return false;
	return true;
}
bool Board::isValidRightPlacement(int x, int y, shipType type) {
	if (x + type > 9)
		return false;
	for (int i = 0; i < type; i++)
		if (doesIndexExist(x+i,y) == true)
			return false;
	return true;
}
bool Board::isValidDownPlacement(int x, int y, shipType type) {
	if (y - type < 0)
		return false;
	for (int i = 0; i < type; i++)
		if (doesIndexExist(x, y - i) == true)
			return false;
	return true;
}
bool Board::isValidLeftPlacement(int x, int y, shipType type) {
	if (x - type < 0)
		return false;
	for (int i = 0; i < type; i++)
		if (doesIndexExist(x-i, y) == true)
			return false;
	return true;
}



void Board::placeShipUp(int x, int y, shipType sType) {
	for (int i = 0; i < sType; i++) {
		_board.push_back(Tile(x, y+i, sType, false));
	}
}

void Board::placeShipRight(int x, int y, shipType sType) {
	for (int i = 0; i < sType; i++) {
		_board.push_back(Tile(x+i, y, sType, false));
	}
}

void Board::placeShipDown(int x, int y, shipType sType) {
	for (int i = 0; i < sType; i++) {
		_board.push_back(Tile(x, y - i, sType, false));
	}
}

void Board::placeShipLeft(int x, int y, shipType sType) {
	for (int i = 0; i < sType; i++) {
		_board.push_back(Tile(x-i, y, sType, false));
	}
}






vector<Tile> Board::getBoard() {
	return _board;
}

boardType Board::getBoardType() {
	return _type;
}

Tile &Board::getTile(int x, int y) {
	for (auto & i : _board) {
		if (i.getXcoord() == x && i.getYcoord() == y)
			return i;
	}
	throw "tile does not exist in board";
}

void Board::placeShip(int x, int y, shipType sType, direction dir) {
	if (!isValidPlacement(x,y,dir,sType))
		throw "cannot place ship on board";

	switch (dir) {
	case up:
		placeShipUp(x, y, sType);
		break;
	case right:
		placeShipRight(x, y, sType);
		break;
	case down:
		placeShipDown(x, y, sType);
		break;
	case left:
		placeShipLeft(x, y, sType);
		break;
	default:
		throw "invalid direction when placing ship on board";
	}
	
}

bool Board::doesIndexExist(int x, int y) {
	for (auto i : _board) {
		if (i.getXcoord() == x && i.getYcoord() == y)
			return true;
	}
	return false;
}

void Board::shootBoard(int x, int y){
	// Empty Spot
	if (doesIndexExist(x,y) == false){
		Tile temp(x,y, noShip, true);
		_board.push_back(temp);
	}
	// Tile already exists
	else if (doesIndexExist(x,y) == true)
	{
		if(getTile(x,y).isHit() == true){
			throw "Spot has already been shot!";
		}
		else{
			getTile(x,y).setIsHit(true);
		}
	}

}

void Board::printBoard(){
	std::cout << std::setw(5) << " ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::setw(5) << i;
	}
	std::cout << std::endl;
	for (int x = 0; x < 10; x++){
		std::cout << std::setw(5) << x;
		for (int y = 0; y < 10; y++){
			if (doesIndexExist(x,y) == true)
			{
				if (getTile(x,y).isHit() == true && getTile(x,y).getShipType() != noShip){
					std::cout << std::setw(5) << "H"; // Hit a ship
				}
				else if (getTile(x,y).isHit() == true){
					std::cout << std::setw(5) << "S"; // Shot but no ship
				}
				else{
					std::cout << std::setw(5) << "W"; // Water / unknown
				}
				
			}
			else{
				std::cout << std::setw(5) << "W"; 	  // Water / unknown
			}
		}
		std::cout << std::endl;
	}
}
