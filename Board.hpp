//Jacob Jakiemiec
//Kelby Hubbard
//Board.hpp

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector> // for std::vector
using std::vector;

using BoardType = vector<vector<char>>; // Holds board layout. To lookup item a,b: board[a][b]

// *********************************************************************
// class Ship - Class definition
// *********************************************************************
class Board {

// ***** Ship: Constructors, Destructors ******
public:
   Board() : _board(10, vector<char>(10, 'e')) {}
 
// ***** Ship: Public Member Functions *****
public:
    BoardType getBoard();
    void shootBoard(int x, int y);

// ***** Ship: Private Data Members *****
private:
    BoardType _board;
};

#endif