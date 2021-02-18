//Jacob Jakiemiec
//Kelby Hubbard
//Tile.hpp

#ifndef TILE_HPP
#define TILE_HPP

//shipType
//contains all types of ships
enum shipType {
	noShip,
	destroyer=2,
	submarine=3,
	cruiser=4,
	battleship=4,
	carrier=5
};


class Tile {
public:
	Tile() : _x(0), _y(0), _type(noShip), _isHit(false) {}
	Tile(int x, int y, shipType type, bool isHit) : _x(x), _y(y), _type(type), _isHit(isHit) {}

	int getXcoord() const;
	int getYcoord() const;
	shipType getShipType() const;
	bool isHit() const;

	void setCoords(int x, int y);
	void setShipType(shipType type);
	void setIsHit(bool isHit);

	bool operator==(const Tile& right) const;
	bool operator!=(const Tile& right) const;
private:
	int _x;
	int _y;
	shipType _type;
	bool _isHit;

};

#endif
