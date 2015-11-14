#include "RegularRoom.h"

#define WALL 0
#define DOOR 1

using namespace std;

RegularRoom::RegularRoom(string pID, int* pAdjacencyList) : Room()
{
	mID = pID;
	mAdjacencyList = new int[4];
	setAdjacencyList(pAdjacencyList);

	cout << "created Regular Room " << mID << endl;
}

RegularRoom::RegularRoom(const RegularRoom& pRegularRoom) : Room(pRegularRoom)
{
	mID = pRegularRoom.mID;
	mAdjacencyList = pRegularRoom.mAdjacencyList;

	cout << "copied Regular Room " << mID << endl;
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
				mAdjacencyList[index] = -1;
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
	// print instance info
	cout << "created Regular Room: " << mID << endl;

	if(mAdjacencyList)
	{
		cout << "adjacency list: [";
		for(int index = 0; index < 4; index++)
		{
			cout << mAdjacencyList[index] << ", ";
		}
		cout << "]" << endl;
	}
}