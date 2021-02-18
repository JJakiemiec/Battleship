#include <iostream>
using std::cout;
#include "board.hpp"
#include "Tile.hpp"

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

    cout << "Each spot is represented by a letter:\n"
         << "W = Water / Unknown\n"
         << "H = HIT! You hit a ship at that location.\n"
         << "S = Shot. You've shot that location but nothing is there.\n";

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

 
    
    return 0;
}
