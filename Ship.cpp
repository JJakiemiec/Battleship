//Jacob Jakiemiec
//Kelby Hubbard
//Ship.cpp

#include "Ship.hpp"

int Ship::getSize()
{
    return _size;
}

bool Ship::isDestroyed()
{
    return _destroyed;
}

vector<int> Ship::getCords()
{
    vector<int> temp;
    temp.push_back(_x1);
    temp.push_back(_y1);
    temp.push_back(_x2);
    temp.push_back(_y2);

    return temp;
}

int Ship::getShipType()
{
    return _shipType;
}