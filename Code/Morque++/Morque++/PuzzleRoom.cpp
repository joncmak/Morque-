#include "PuzzleRoom.h"

#define WALL 0
#define DOOR 1

using namespace std;

PuzzleRoom::PuzzleRoom(int pID, int* pAdjacencyList) : Room()
{
	mID = pID;
	mAdjacencyList = new int[4];
	setAdjacencyList(pAdjacencyList);
	cout << "created Puzzle Room " << mID << endl;
}

PuzzleRoom::PuzzleRoom(const PuzzleRoom& pPuzzleRoom) : Room(pPuzzleRoom)
{
	mID = pPuzzleRoom.mID + 1;
	mAdjacencyList = pPuzzleRoom.mAdjacencyList;
	cout << "copied Puzzle Room " << mID << endl;
}

void PuzzleRoom::setAdjacencyList(int* pAdjacencyList)
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

Room* PuzzleRoom::clone()
{
	return new PuzzleRoom(*this);
}

void PuzzleRoom::print()
{
	cout << "created Puzzle Room " << mID << endl;
	cout << "adjacency list: [";
	for(int index = 0; index < 4; index++)
	{
		cout << mAdjacencyList[index] << ", ";
	}
	cout << "]" << endl;
}

