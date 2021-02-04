//Jacob Jakiemiec
//Kelby Hubbard
//ship.hpp

#ifndef SHIP_HPP
#define SHIP_HPP

// *********************************************************************
// class Ship - Class definition
// *********************************************************************
class Ship {

// ***** Ship: Constructors, Destructors ******
public:
    Ship(int size) :_size(size) {}


// ***** Ship: Public Member Functions *****
public:
    int getSize();

// ***** Ship: Private Data Members *****
private:
    int _size;  


};

#endif