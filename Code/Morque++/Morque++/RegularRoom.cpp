#include "RegularRoom.h"

#define WALL 0
#define DOOR 1

using namespace std;

///
/// Constructor for RegularRoom
///
/// Parameters:
/// string pID - uuid for instance of RegularRoom
/// int* pAdjacencyList - integer array for adjacency list
///
RegularRoom::RegularRoom(string pID, int* pAdjacencyList) : Room()
{
	if(pID == "")
	{
		boost::uuids::uuid uuid = boost::uuids::random_generator()();
		pID = boost::lexical_cast<std::string>(uuid);
	}

	mID = pID;
	
	if(pAdjacencyList != NULL)
	{
		mAdjacencyList = new int[4];
		setAdjacencyList(pAdjacencyList);
	}

	cout << "created Regular Room " << mID << endl;
}

///
/// Copy Constructor for RegularRoom
///
/// Parameters:
/// RegularRoom& pRegularRoom - instance of RegularRoom to copy
///
RegularRoom::RegularRoom(const RegularRoom& pRegularRoom) : Room(pRegularRoom)
{
	mID = pRegularRoom.mID;
	mAdjacencyList = pRegularRoom.mAdjacencyList;

	cout << "copied Regular Room " << mID << endl;
}

///
/// setAdjacencyList
///
/// Sets the adjacency list for RegularRoom.
/// If a valud in the integer array is invalid, it defaults to 0 (WALL)
///
/// Parameters:
/// int* pAdjacencyList - integer array to use for adjacency list
///
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
				mAdjacencyList[index] = WALL;
			}
		}
	}
}

///
/// clone()
///
/// clone function for RegularRoom
///
/// Returns: cloned instance of RegularRoom
///
Room* RegularRoom::clone()
{
	return new RegularRoom(*this);
}

///
/// print()
///
/// Prints information about the current instance of RegularRoom
///
void RegularRoom::print()
{
	// print instance info
	cout << "created Regular Room: " << mID << endl;

//	cout << "adjacency list: [";
//	for(int index = 0; index < 4; index++)
//	{
//		cout << mAdjacencyList[index] << ", ";
//	}
//	cout << "]" << endl;
}