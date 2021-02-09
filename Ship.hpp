//Jacob Jakiemiec
//Kelby Hubbard
//ship.hpp

#ifndef SHIP_HPP
#define SHIP_HPP

//#include "Board.hpp"
#include <tuple>
#include <vector> // for std::vector
#include <utility> // for std::pair
using std::vector;

// *********************************************************************
// class Ship - Class definition
// *********************************************************************
class Ship {

// ***** Ship: Constructors, Destructors ******
public:
    Ship(int shipType, int x1, int y1, int x2, int y2) 
        :_shipType(shipType),
        _x1(x1),
        _y1(y1),
        _x2(x2),
        _y2(y2),
        _destroyed(false)
    {
		_size = shipType;
		if (shipType == 1 || shipType == 2)
		{
			_size += 1;
		}

        // FIXME: Need to fill in not hit for spaces between start and end
        /*_hits.push_back(std::make_tuple(x1,y1,0));
        _hits.push_back(std::make_tuple(x2,y2,0));*/

		//fill the spaces for hits
		//determine if the ship is horizontal or vertical
		//ship is vertical
		if (x1 == x2) {
			//ship is pointing up
			if (y1 > y2) {
				for (int i = 0; i < _size; i++) {
					_hits.push_back(std::make_tuple(x1, y1 - i, 0));
				}
			}
			//ship is pointing down
			else {
				for (int i = 0; i < _size; i++) {
					_hits.push_back(std::make_tuple(x1, y1 + i, 0));
				}
			}
		}
		//ship is horizontal
		else {
			//ship is pointing left
			if (x1 > x2) {
				for (int i = 0; i < _size; i++) {
					_hits.push_back(std::make_tuple(x1 - i, y1, 0));
				}
			}
			//ship is pointing right
			else {
				for (int i = 0; i < _size; i++) {
					_hits.push_back(std::make_tuple(x1 + i, y1, 0));
				}
			}
		}

        
    }


// ***** Ship: Public Member Functions *****
public:
    int getSize();
    bool isDestroyed();
    vector<int> getCords(); // Returns cords in this order: (x1,y1,x2,y2)
    int getShipType();
	vector<std::tuple<int, int, int>> getHits();


// ***** Ship: Private Data Members *****
private:
    int _size;                               // 2 -> 5
    bool _destroyed;                         // If true ship is dead, if false ship is alive
    int _x1, _y1, _x2, _y2;                  // x1,y1 is start of ship x2,y2 is end of ship
    int _shipType;
    vector<std::tuple<int,int,int>> _hits;
};

#endif