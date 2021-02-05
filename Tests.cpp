//Jacob Jakiemiec
//Kelby Hubbard
//Tests.cpp 
#include "catch.hpp"
#include "Ship.hpp"
#include "Board.hpp"

TEST_CASE( "Board Design" )
 {
    Board board;
    
    SECTION( "Generate a 10x10 board of no hits ")
    {
        BoardType temp = board.getBoard();
        REQUIRE( temp[0][0] == 'e' );
        REQUIRE( temp[0][6] == 'e' );
        REQUIRE( temp[3][9] == 'e' );
        REQUIRE( temp[9][2] == 'e' );
    }

    SECTION ( "Mark a shot space as shot") 
    {
        board.shootBoard(0,0);
        board.shootBoard(3,8);
        board.shootBoard(9,0);
        BoardType temp = board.getBoard();
        
        REQUIRE( temp[0][0] == 's');
        REQUIRE( temp[3][8] == 's');
        REQUIRE( temp[9][0] == 's');
        
    }
}
