#pragma once
#include <map>
#include <string>
#include "Room.h"
#include "RegularRoom.h"
#include "PuzzleRoom.h"

using namespace std;

///
/// Prototype Factory
/// 
/// Creates and clones instances of Room
/// and all subclasses
///
class MapPrototypeFactory
{
public:
	MapPrototypeFactory();
	MapPrototypeFactory(Room*);
	~MapPrototypeFactory();

	virtual Room* makeRoom();
	virtual Room* getRoom();
private:
	Room* mPrototypeRoom;
};

