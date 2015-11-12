#include "MapPrototypeFactory.h"

MapPrototypeFactory::MapPrototypeFactory()
{
}

MapPrototypeFactory::MapPrototypeFactory(Room* pRoom)
{
	mPrototypeRoom = pRoom;
}

MapPrototypeFactory::~MapPrototypeFactory()
{
}

Room* MapPrototypeFactory::makeRoom()
{
	return mPrototypeRoom->clone();
}

Room* MapPrototypeFactory::getRoom()
{
	return mPrototypeRoom;
}
