//Jacob Jakiemiec
//Kelby Hubbard
//Tests.cpp 
#include "Catch.hpp"
#include "Ship.hpp"
#include "Board.hpp"

TEST_CASE( "Board Design" )
 {
    Board board;
    
	SECTION("Generate a 10x10 board of no hits ")
	{
		BoardType temp = board.getBoard();
		 REQUIRE( temp[0][0].first == 0 );
		 REQUIRE( temp[0][6].first == 0 );
		 REQUIRE( temp[3][9].first == 0 );
		 REQUIRE( temp[9][2].first == 0 );
	}
    SECTION ( "Mark a shot space as shot") 
    {
        board.shootBoard(0,0);
        board.shootBoard(3,8);
        board.shootBoard(9,0);
        BoardType temp = board.getBoard();

        REQUIRE( temp[0][0].first == 1);
        REQUIRE( temp[3][8].first == 1);
        REQUIRE( temp[9][0].first == 1);
        REQUIRE( temp[1][1].first == 0);
        
    }
}

TEST_CASE( "Ship Design" )
{
    Ship smallship(2, 0,0, 0,2);
    SECTION ( "Generate small ship of correct size and stats" )
    {
        REQUIRE(smallship.getSize() == 3);
        REQUIRE(smallship.isDestroyed() == false);
		REQUIRE(smallship.getCords() == vector<int>{0, 0, 0, 2});
		REQUIRE(smallship.getHits()[0] == std::tuple<int, int, int>{0, 0, 0});
		REQUIRE(smallship.getHits()[1] == std::tuple<int, int, int>{0, 1, 0});
		REQUIRE(smallship.getHits()[2] == std::tuple<int, int, int>{0, 2, 0});
        // FIXME: Add shot checking / hit checking
    }
	Ship bigship(5, 3, 3, 3, 7);
	SECTION("Generate big ship of correct size and stats") {
		REQUIRE(bigship.getSize() == 5);
		REQUIRE(bigship.isDestroyed() == false);
		REQUIRE(bigship.getCords() == vector<int>{3, 3, 3, 7});
		REQUIRE(bigship.getHits()[0] == std::tuple<int, int, int>{3, 3, 0});
		REQUIRE(bigship.getHits()[1] == std::tuple<int, int, int>{3, 4, 0});
		REQUIRE(bigship.getHits()[2] == std::tuple<int, int, int>{3, 5, 0});
		REQUIRE(bigship.getHits()[3] == std::tuple<int, int, int>{3, 6, 0});
		REQUIRE(bigship.getHits()[4] == std::tuple<int, int, int>{3, 7, 0});
	}
}
