//Jacob Jakiemiec
//Kelby Hubbard
//board.hpp


#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include <vector>
using std::vector;
#include <exception>

//boardType
//used to tell what kind of board the current board object is
enum boardType {
	placementBoard,
	guessingBoard
};

//direction
enum direction {
	up,
	down,
	left,
	right
};

class Board {
public:
	Board(): _type(placementBoard) {}
	Board(boardType type) : _type(type) {}

	vector<Tile> getBoard();
	boardType getBoardType();

	Tile getTile(int x, int y);
	void placeShip(int x, int y,  shipType sType, direction dir);
	bool doesIndexExist(int x, int y);
	bool isValidPlacement(int x, int y, direction dir, shipType type);
	void shootBoard(int x, int y);
	void createDefault();

private:
	vector<Tile> _board;
	boardType _type;

	
	bool isValidUpPlacement(int x, int y, shipType type);
	bool isValidRightPlacement(int x, int y,  shipType type);
	bool isValidDownPlacement(int x, int y, shipType type);
	bool isValidLeftPlacement(int x, int y, shipType type);

	void placeShipUp(int x, int y, shipType sType);
	void placeShipRight(int x, int y, shipType sType);
	void placeShipDown(int x, int y, shipType sType);
	void placeShipLeft(int x, int y, shipType sType);
};


#endif
