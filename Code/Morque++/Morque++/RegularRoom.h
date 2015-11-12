#pragma once
#include "Room.h"
#include <iostream>
#include <string>

class RegularRoom : public Room
{
public:
	RegularRoom(int, int*);
	RegularRoom(const RegularRoom&);
	~RegularRoom() {};

	Room* clone();
	void print();

private:
	int mID;
	int* mAdjacencyList;
	void setAdjacencyList(int*);
};