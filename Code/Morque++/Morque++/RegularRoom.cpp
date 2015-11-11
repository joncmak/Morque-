#include "RegularRoom.h"
#include <iostream>
#include <string>

#define WALL 0
#define DOOR 1


RegularRoom::RegularRoom(int pID, int* pAdjacencyList) : Room()
{
	mID = pID;
	setAdjacencyList(pAdjacencyList);
}

RegularRoom::RegularRoom(const RegularRoom& pRegularRoom) : Room(pRegularRoom)
{
	mID = pRegularRoom.mID;
	mAdjacencyList = pRegularRoom.mAdjacencyList;
}

void RegularRoom::setAdjacencyList(int* pAdjacencyList)
{
	if(sizeof(pAdjacencyList) != 4)
	{
		//error log
	}
	else
	{
		int index;
		for(index = 0; index < 4; index++)
		{
			if(pAdjacencyList[index] == WALL)
			{
				mAdjacencyList[index] = WALL;
			}
			else if(pAdjacencyList[index] == DOOR)
			{
				mAdjacencyList[index] = DOOR;
			}
			else
			{
				//error log
			}
		}
	}
}

Room* RegularRoom::clone()
{
	return new RegularRoom(*this);
}

void RegularRoom::print()
{
	std::cout << "hello world" << std::endl;
}