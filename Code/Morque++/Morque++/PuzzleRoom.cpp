#include "PuzzleRoom.h"

#define WALL 0
#define DOOR 1

using namespace std;

///
/// Constructor for PuzzleRoom
///
/// Parameters:
/// string pID - uuid for instance of PuzzleRoom
/// int* pAdjacencyList - integer array for adjacency list
///
PuzzleRoom::PuzzleRoom(string pID, int* pAdjacencyList) : Room()
{
	mID = pID;
	mAdjacencyList = new int[4];
	setAdjacencyList(pAdjacencyList);

	cout << "created Puzzle Room " << mID << endl;
}

///
/// Copy Constructor for PuzzleRoom
///
/// Parameters:
/// PuzzleRoom& pPuzzleRoom - instance of PuzzleRoom to copy
///
PuzzleRoom::PuzzleRoom(const PuzzleRoom& pPuzzleRoom) : Room(pPuzzleRoom)
{
	mID = pPuzzleRoom.mID;
	mAdjacencyList = pPuzzleRoom.mAdjacencyList;

	cout << "copied Puzzle Room " << mID << endl;
}

///
/// setAdjacencyList
///
/// Sets the adjacency list for PuzzleRoom.
/// If a valud in the integer array is invalid, it defaults to 0 (WALL)
///
/// Parameters:
/// int* pAdjacencyList - integer array to use for adjacency list
///
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

///
/// clone()
///
/// clone function for PuzzleRoom
///
/// Returns: cloned instance of PuzzleRoom
///
Room* PuzzleRoom::clone()
{
	return new PuzzleRoom(*this);
}

///
/// print()
///
/// Prints information about the current instance of PuzzleRoom
///
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