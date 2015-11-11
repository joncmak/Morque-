#include "MapPrototypeFactory.h"
#include <iostream>
#include <string>
#include <map>
#include <random>

enum ROOM_TYPE{ REGULAR, PUZZLE, TRAP };

std::map<ROOM_TYPE, Room*> mRoomRef;

MapPrototypeFactory::MapPrototypeFactory(std::string pClassName, int* pAdjacencyList)
{
	if(pClassName == "RegularRoom")
	{
		RegularRoom* room = new RegularRoom(rand()%2, pAdjacencyList);
		//mRoomRef[REGULAR] = room;
		
	}
	else if(pClassName == "PuzzleRoom")
	{

	}
	else if(pClassName == "TrapRoom")
	{

	}
	else
	{

	}
}

Room* MapPrototypeFactory::makeRoom(ROOM_TYPE pType)
{
	return mRoomRef[pType]->clone();
}