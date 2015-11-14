#include "MapPrototypeFactory.h"

///
/// Default Constructor
///
MapPrototypeFactory::MapPrototypeFactory()
{
}

///
/// Constructor
///
/// Parameters: 
/// Room* pRoom - Room prototype to use in factory
///
MapPrototypeFactory::MapPrototypeFactory(Room* pRoom)
{
	mPrototypeRoom = pRoom;
}

MapPrototypeFactory::~MapPrototypeFactory()
{
}

///
/// makeRoom
///
/// returns: Instance clone of Room
///
Room* MapPrototypeFactory::makeRoom()
{
	return mPrototypeRoom->clone();
}

///
/// getRoom
///
/// returns: Current instance of Room
///
Room* MapPrototypeFactory::getRoom()
{
	return mPrototypeRoom;
}
