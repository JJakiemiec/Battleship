//Jacob Jakiemiec
//Kelby Hubbard
//Board.cpp

#include "Board.hpp"

BoardType Board::getBoard()
{
    return _board;
}

void Board::shootBoard(int x, int y){
    _board[x][y] = 1; // (1 == shot)

}