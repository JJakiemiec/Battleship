//Jacob Jakiemiec
//Kelby Hubbard
//ship.hpp

#ifndef SHIP_HPP
#define SHIP_HPP

#include "Board.hpp"
#include <tuple>

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
        // FIXME: Need to fill in not hit for spaces between start and end
        _hits.push_back(std::make_tuple(x1,y1,0));
        _hits.push_back(std::make_tuple(x2,y2,0));

        _size = shipType;
        if(shipType == 1 || shipType == 2)
        {
            _size += 1;
        }
    }


// ***** Ship: Public Member Functions *****
public:
    int getSize();
    bool isDestroyed();

// ***** Ship: Private Data Members *****
private:
    int _size;                               // 2 -> 5
    bool _destroyed;                         // If true ship is dead, if false ship is alive
    int _x1, _y1, _x2, _y2;                  // x1,y1 is start of ship x2,y2 is end of ship
    int _shipType;
    vector<std::tuple<int,int,int>> _hits;
};

#endif