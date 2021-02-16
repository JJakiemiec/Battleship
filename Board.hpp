//Jacob Jakiemiec
//Kelby Hubbard
//Board.hpp

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector> // for std::vector
#include <utility> // for std::pair
using std::vector;
#include "Ship.hpp"

// Holds board layout. To lookup item a,b: board[a][b]
// First int is hit or not hit (0 not hit / 1 hit)
// Second int what kind of ship:
//      0 : No ship
//      1 : Destroyer   (size 2)
//      2 : Submarine   (size 3)
//      3 : Cruiser     (size 3)
//      4 : Battleship  (size 4)
//      5 : Carrier     (size 5)
//
// Boardtype holds the what is the type of the current board
//		0 : player's placable board, where the player places ships and records opponent's shots
//		1 : player's guessing board, where the player keeps tracks of hits and misses of opponent's ships

using BoardType = vector<vector<std::pair<int,int>>>; 
// *********************************************************************
// class Ship - Class definition
// *********************************************************************
class Board {

// ***** Ship: Constructors, Destructors ******
public:
	Board() : _board(10, vector<std::pair<int,int>>(10, std::make_pair(0,0))), _boardType(0) {}
	Board(int boardType) : _board(10, vector<std::pair<int, int>>(10, std::make_pair(0, 0))), _boardType(boardType) {}
// ***** Ship: Public Member Functions *****
public:
    BoardType getBoard();
	vector<vector<char>> getPrintableBoard();
    void shootBoard(int x, int y);
    void placeShip(Ship ship);
	char getPrintableChar(int i, int j);

// ***** Ship: Private Data Members *****
private:
    BoardType _board;
	int _boardType;						
};

#endif