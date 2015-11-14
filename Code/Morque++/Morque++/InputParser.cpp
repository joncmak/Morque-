#include "InputParser.h"

#define WALL 0
#define DOOR 1
#define FILENAME "savefile"

std::string InputParser::getClassName()
{
	std::string classname = "";
	std::cout << "enter classname" << std::endl;
	std::cin >> classname;
	return (classname == "RegularRoom" || classname == "PuzzleRoom" || "TrapRoom") ? classname: "";
}

int* InputParser::getAdjList()
{
	int inAdjList = 0;
	int* adjList = new int[4];
	
	std::cout << "enter adj list " << std::endl;
	int index;
	for(index=0; index< 4; index++)
	{
		std::cout << index << ": " << std::endl;
		std::cin >> inAdjList;
		 
		adjList[index] = (inAdjList == WALL || inAdjList == DOOR) ? inAdjList : -1;
	}
	return adjList;
}

std::string InputParser::genID()
{
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	std::string stringID = boost::lexical_cast<std::string>(uuid);
	return stringID;
}

void InputParser::loadSaveFile()
{
	RegularRoom* room;
	std::ifstream ifs(FILENAME);
	boost::archive::text_iarchive ar(ifs);
	ar & room;

	cout << "loaded successfully" << endl;
	room->print();
}

void InputParser::getCommand()
{
	MapPrototypeFactory* factory = NULL;

	while(true)
	{
		std::string action;
		
		std::cout << "enter command [create|print|quit]" << std::endl;
		std::cin >> action;
		
		if(action == "quit")
		{
			break;
		}
		else if (action == "create")
		{
			std::string classname = getClassName();
			int* adjList = getAdjList();

			if(classname == "RegularRoom")
			{
				RegularRoom* room = new RegularRoom(genID(), adjList);
				factory = new MapPrototypeFactory(room);

				std::string save = "";
				cout << "save? (y|n)" << endl;
				cin >> save;

				if(save == "y")
				{
					std::ofstream ofs(FILENAME);
					boost::archive::text_oarchive ar(ofs);
					ar & room;
				}
			}
			else if(classname == "PuzzleRoom")
			{
				PuzzleRoom* room = new PuzzleRoom(genID(), adjList);
				factory = new MapPrototypeFactory(room);

				std::string save = "";
				cout << "save? (y|n)" << endl;
				cin >> save;

				if(save == "y")
				{
					std::ofstream ofs(FILENAME);
					boost::archive::text_oarchive ar(ofs);
					ar & room;
				}
			}
			else
			{
				std::cout << "invalid classname" << std::endl;
			}
		}
		else if (action == "print")
		{
			if(NULL == factory)
			{
				std::cout << "no instance" << std::endl;
			}
			else
			{
				//todo print all
				Room* room = factory->getRoom();
				room->print();
			}
		}
		else
		{
			std::cout << "invalid action" << std::endl;
		}
	}
}