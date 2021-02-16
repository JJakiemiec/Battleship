//Jacob Jakiemiec
//Kelby Hubbard
//Board.cpp

#include "Board.hpp"

BoardType Board::getBoard()
{
    return _board;
}

char Board::getPrintableChar(int i, int j) {
	if (_board[i][j].first == 0)
		return '*';
	else {
		if (_boardType == 0) {
			return '?';
		}
		else
			if (_board[i][j].second == 0)
				return 'O';
			else
				return 'X';
	}
}

//getPrintableBoard outputs a 2D array of chars that represent the board
// * : represents a blank spot
// O : represents a player's guess that missed
// X : represents a player's guess that hit
// ? : represents an error (hasn't been implemented yet
vector<vector<char>> Board::getPrintableBoard()
{
	vector<vector<char>> temp(10, vector<char>(10, '?'));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			temp[i][j] = getPrintableChar(i, j);
		}
	}
	return temp;
}

void Board::shootBoard(int x, int y){
   _board[x][y].first = 1; // (1 == shot)

   if (_board[x][y].second > 0) // >0 means ship exists on that spot
   {
	   switch(_board[x][y].second)
	   {
			case 1:	// Destroyer is here (size 2)
				// Mark ship as hit
				break;
			case 2:	// Submarine is here (size 3)
				// Mark ship as hit
				break;
			case 3:	// Cruiser is here	 (size 3)
				// Mark ship as hit
				break;
			case 4:	// Battleship is here(size 4)
				// Mark ship as hit
				break;
			case 5: // Carrier is here 	 (size 5)
				// Mark ship as hit
				break;
	   }
   }
   else
   {
	   // FIXME: No ship was hit. Announce to player?
   }

}

void Board::placeShip(Ship ship)
{
    vector<int> cords = ship.getCords();
    
}