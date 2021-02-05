//Jacob Jakiemiec
//Kelby Hubbard
//Tests.cpp 
#include "catch.hpp"
#include "Ship.hpp"
#include "Board.hpp"

TEST_CASE( "Board Design" ) {

    Board board;
    BoardType temp = board.getBoard();
    // Generate a 10x10 board of no hits?
    REQUIRE( temp[0][0] == 'e' );
    REQUIRE( temp[0][6] == 'e' );
    REQUIRE( temp[3][9] == 'e' );
    REQUIRE( temp[9][2] == 'e' );
}