//Jacob Jakiemiec
//Kelby Hubbard
//Tile.cpp

#include "Tile.hpp"

int Tile::getXcoord() const{
	return _x;
}

int Tile::getYcoord() const{
	return _y;
}

shipType Tile::getShipType() const{
	return _type;
}

bool Tile::isHit() const{
	return _isHit;
}

void Tile::setCoords(int x, int y) {
	_x = x;
	_y = y;
}

void Tile::setShipType(shipType type) {
	_type = type;
}

void Tile::setIsHit(bool isHit) {
	_isHit = isHit;
}

bool Tile::operator==(const Tile& right) const{
	if (_x != right.getXcoord())
		return false;
	if (_y != right.getYcoord())
		return false;
	if (_type != right.getShipType())
		return false;
	if (_isHit != right.isHit())
		return false;
	return true;
}

bool Tile::operator!=(const Tile& right) const {
	return !(*this == right);
}