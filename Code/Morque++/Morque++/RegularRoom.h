#pragma once
#include "Room.h"
#include <iostream>
#include <string>

class RegularRoom : public Room
{
public:
	RegularRoom(std::string, int*);
	RegularRoom(const RegularRoom&);
	~RegularRoom() {};

	Room* clone();
	void print();

private:
	std::string mID;
	int* mAdjacencyList;
	void setAdjacencyList(int*);
};