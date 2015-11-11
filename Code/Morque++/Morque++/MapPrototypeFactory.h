#include "Room.h"
#include "RegularRoom.h"
#include <string>

enum ROOM_TYPE{ REGULAR, PUZZLE, TRAP };

class MapPrototypeFactory
{
public:
	MapPrototypeFactory(std::string, int*);
	virtual Room* makeRoom(ROOM_TYPE);

private:
	Room* _prototypeRoom;
};

