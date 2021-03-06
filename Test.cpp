// //Jacob Jakiemiec
// //Kelby Hubbard

// #include "Catch.hpp"
// #include "Tile.hpp"
// #include "board.hpp"
// #include <iostream>

// TEST_CASE("Tile testing") {
// 	SECTION("creating tiles") {
// 		Tile testTile;
// 		REQUIRE(testTile.getShipType() == noShip);
// 		REQUIRE(testTile.getXcoord() == 0);
// 		REQUIRE(testTile.getYcoord() == 0);
// 		REQUIRE(testTile.isHit() == false);

// 		Tile testTile2(5, 4, battleship, true);
// 		REQUIRE(testTile2.getShipType() == battleship);
// 		REQUIRE(testTile2.getXcoord() == 5);
// 		REQUIRE(testTile2.getYcoord() == 4);
// 		REQUIRE(testTile2.isHit() == true);
// 	}
// 	SECTION("modifying tiles") {
// 		Tile testTile;
// 		testTile.setCoords(8, 9);
// 		testTile.setShipType(destroyer);
// 		REQUIRE(testTile.getShipType() == destroyer);
// 		REQUIRE(testTile.getXcoord() == 8);
// 		REQUIRE(testTile.getYcoord() == 9);
// 		REQUIRE(testTile.isHit() == false);
// 	}
// 	SECTION("Comparing tiles") {
// 		Tile testTile;
// 		Tile testTile2;
// 		Tile testTile3(2, 2, submarine, true);
// 		REQUIRE(testTile == testTile2);
// 		REQUIRE(testTile != testTile3);
// 		REQUIRE(testTile2 != testTile3);
// 	}
// }

// TEST_CASE("Board creation") {
// 	SECTION("creating the board") {
// 		Board testBoard;
// 		vector<Tile> testVector;
// 		REQUIRE(testBoard.getBoard().size() == 0);
// 		REQUIRE(testBoard.getBoard() == testVector);
// 		REQUIRE(testBoard.getBoardType() == placementBoard);	
// 	}
// }

// TEST_CASE("Placing ships on the board") {
// 	SECTION("Recognizes is ship is attempting to be placed at an invalid location") {
// 		Board testBoard;
// 		testBoard.placeShip(1, 3, battleship, up);
// 		REQUIRE(testBoard.isValidPlacement(-1, 0, left, battleship) == false);
// 		REQUIRE(testBoard.isValidPlacement(0, -1, down, battleship) == false);
// 		REQUIRE(testBoard.isValidPlacement(10, 0, right, battleship) == false);
// 		REQUIRE(testBoard.isValidPlacement(0, 10, up, battleship) == false);
// 		REQUIRE(testBoard.isValidPlacement(1, 3, up, battleship) == false);
// 		REQUIRE(testBoard.isValidPlacement(8, 8, left, battleship) == true);
// 	}
// 	SECTION("places ships") {
// 		Board testBoard;
// 		testBoard.placeShip(0, 0, battleship, up);
// 		for (int i = 0; i < battleship; i++) {
// 			REQUIRE(testBoard.doesIndexExist(0, 0+i) == true);
// 			REQUIRE(testBoard.getTile(0, 0+i) == Tile(0, 0+i, battleship, false));
// 		}
// 		testBoard.placeShip(1, 0, destroyer, right);
// 		for (int i = 0; i < destroyer; i++) {
// 			REQUIRE(testBoard.doesIndexExist(1+i,0) == true);
// 			REQUIRE(testBoard.getTile(1+i,0) == Tile(1+i,0, destroyer, false));
// 		}
// 		testBoard.placeShip(9, 9, submarine, down);
// 		for (int i = 0; i < submarine; i++) {
// 			REQUIRE(testBoard.doesIndexExist(9,9-i) == true);
// 			REQUIRE(testBoard.getTile(9,9-i) == Tile(9,9-i, submarine, false));
// 		}
// 		testBoard.placeShip(8, 9, carrier, left);
// 		for (int i = 0; i < carrier; i++) {
// 			REQUIRE(testBoard.doesIndexExist(8-i,9) == true);
// 			REQUIRE(testBoard.getTile(8-i,9) == Tile(8-i,9, carrier, false));
// 		}
// 	}	
// }

// TEST_CASE("Shooting board") {
// 	SECTION("Can shoot empty spot and marks as hit"){
// 		Board testBoard;

// 		testBoard.shootBoard(3,1);
// 		REQUIRE(testBoard.getTile(3,1).isHit() == true);

// 		testBoard.shootBoard(4,3);
// 		REQUIRE(testBoard.getTile(4,3).isHit() == true);

// 		testBoard.shootBoard(7,0);
// 		REQUIRE(testBoard.getTile(7,0).isHit() == true);

// 	}
// 	SECTION("Cannot shoot at already shot spot"){
// 		Board testBoard;

// 		testBoard.shootBoard(0,0);
// 		REQUIRE(testBoard.getTile(0,0).isHit() == true);
// 		REQUIRE_THROWS_WITH(testBoard.shootBoard(0,0), "Spot has already been shot!");

// 		testBoard.shootBoard(6,3);
// 		REQUIRE(testBoard.getTile(6,3).isHit() == true);
// 		REQUIRE_THROWS_WITH(testBoard.shootBoard(6,3), "Spot has already been shot!");

// 		testBoard.shootBoard(0,8);
// 		REQUIRE(testBoard.getTile(0,8).isHit() == true);
// 		REQUIRE_THROWS_WITH(testBoard.shootBoard(0,8), "Spot has already been shot!");


// 	}
// 	SECTION("If hits ship, mark ship as hit"){
// 		Board testBoard;

// 		testBoard.placeShip(4,4, battleship, down);
// 		REQUIRE(testBoard.getTile(4,4).isHit() == false);
// 		testBoard.shootBoard(4,4);
// 		REQUIRE(testBoard.getTile(4,4).isHit() == true);

// 		testBoard.placeShip(3,6, destroyer, right);
// 		REQUIRE(testBoard.getTile(3,6).isHit() == false);
// 		testBoard.shootBoard(3,6);
// 		REQUIRE(testBoard.getTile(3,6).isHit() == true);
// 		REQUIRE(testBoard.getTile(4,6).isHit() == false);
// 		testBoard.shootBoard(4,6);
// 		REQUIRE(testBoard.getTile(4,6).isHit() == true);

// 		testBoard.placeShip(0,0, cruiser, up);
// 		REQUIRE(testBoard.getTile(0,0).isHit() == false);
// 		testBoard.shootBoard(0,0);
// 		REQUIRE(testBoard.getTile(0,0).isHit() == true);
// 	}
// }