#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "RegularRoom.h"
#include "PuzzleRoom.h"
#include <string>

///
/// Regular Room Unit Tests
///
BOOST_AUTO_TEST_CASE(RegularRoomDefaultConstructor)
{
	RegularRoom* room = new RegularRoom();
	std::string id = room->getID();

	BOOST_CHECK_EQUAL("0", id);
}

BOOST_AUTO_TEST_CASE(RegularRoomConstructor)
{
	RegularRoom* room = new RegularRoom("TestID", NULL);
	std::string id = room->getID();

	BOOST_CHECK_EQUAL("TestID", id);
}

BOOST_AUTO_TEST_CASE(RegularRoomConstructorNoID)
{
	RegularRoom* room = new RegularRoom("", NULL);
	std::string id = room->getID();

	BOOST_CHECK(id != "");
}

BOOST_AUTO_TEST_CASE(RegularRoomClone)
{
	RegularRoom* room = new RegularRoom("TestID Copy", NULL);

	RegularRoom* copy = room;

	BOOST_CHECK_EQUAL(room, copy);
}

BOOST_AUTO_TEST_CASE(RegularRoomConstructorIntList)
{
	int list[4] = {0, 0, 1, 1};

	RegularRoom* room = new RegularRoom("", list);
	std::string id = room->getID();

	BOOST_CHECK(id != "");
	for(int index = 0; index < 4; index++)
	{
		BOOST_CHECK_EQUAL(room->getAdjacencyList()[index], list[index]);
	}
}

BOOST_AUTO_TEST_CASE(RegularRoomConstructorIntListInvalid)
{
	int list[4] = {2, 3, 4, 5};

	RegularRoom* room = new RegularRoom("", list);
	std::string id = room->getID();

	BOOST_CHECK(id != "");

	int expectedResult[4] = {0,0,0,0};
	for(int index = 0; index < 4; index++)
	{
		BOOST_CHECK_EQUAL(room->getAdjacencyList()[index], expectedResult[index]);
	}
}

///
/// Puzzle Room Unit Tests
///
BOOST_AUTO_TEST_CASE(PuzzleRoomDefaultConstructor)
{
	PuzzleRoom* room = new PuzzleRoom();
	std::string id = room->getID();

	BOOST_CHECK_EQUAL("0", id);
}

BOOST_AUTO_TEST_CASE(PuzzleRoomConstructor)
{
	PuzzleRoom* room = new PuzzleRoom("TestID", NULL);
	std::string id = room->getID();

	BOOST_CHECK_EQUAL("TestID", id);
}

BOOST_AUTO_TEST_CASE(PuzzleRoomConstructorNoID)
{
	PuzzleRoom* room = new PuzzleRoom("", NULL);
	std::string id = room->getID();

	BOOST_CHECK(id != "");
}

BOOST_AUTO_TEST_CASE(PuzzleRoomClone)
{
	PuzzleRoom* room = new PuzzleRoom("TestID Copy", NULL);

	PuzzleRoom* copy = room;

	BOOST_CHECK_EQUAL(room, copy);
}

BOOST_AUTO_TEST_CASE(PuzzleRoomConstructorIntList)
{
	int list[4] = {0, 0, 1, 1};

	PuzzleRoom* room = new PuzzleRoom("", list);
	std::string id = room->getID();

	BOOST_CHECK(id != "");

	for(int index = 0; index < 4; index++)
	{
		BOOST_CHECK_EQUAL(room->getAdjacencyList()[index], list[index]);
	}
}

BOOST_AUTO_TEST_CASE(PuzzleRoomConstructorIntListInvalid)
{
	int list[4] = {2, 3, 4, 5};

	PuzzleRoom* room = new PuzzleRoom("", list);
	std::string id = room->getID();

	BOOST_CHECK(id != "");

	int expectedResult[4] = {0,0,0,0};
	for(int index = 0; index < 4; index++)
	{
		BOOST_CHECK_EQUAL(room->getAdjacencyList()[index], expectedResult[index]);
	}
}