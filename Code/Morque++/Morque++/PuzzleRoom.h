#pragma once
#include "room.h"
#include <iostream>
#include <string>

class PuzzleRoom :
	public Room
{
public:
	PuzzleRoom(int, int*);
	PuzzleRoom(const PuzzleRoom&);
	~PuzzleRoom(void) {};

	Room* clone();
	void print();
private:
	int mID;
	int* mAdjacencyList;
	void setAdjacencyList(int*);
};

