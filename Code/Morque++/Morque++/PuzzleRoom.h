#pragma once
#include "room.h"
#include <iostream>
#include <string>

class PuzzleRoom :
	public Room
{
public:
	PuzzleRoom(std::string, int*);
	PuzzleRoom(const PuzzleRoom&);
	~PuzzleRoom(void) {};

	Room* clone();
	void print();
private:
	std::string mID;
	int* mAdjacencyList;
	void setAdjacencyList(int*);
};

