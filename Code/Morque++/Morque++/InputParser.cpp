#include "InputParser.h"

#define WALL 0
#define DOOR 1
#define FILENAME "savefile"

///
/// getClassName
///
/// Gathers user input for a class name. Validates classroom name.
/// If invalid, return empty string
///
/// Returns: name of the class to create.
///
std::string InputParser::getClassName()
{
	std::string classname = "";
	std::cout << "enter classname" << std::endl;
	std::cin >> classname;
	return (classname == "RegularRoom" || classname == "PuzzleRoom") ? classname: "";
}

///
/// getAdjList()
///
/// Gather user input for an adjacency list.
/// Specifies which sides of the room are walls/doors.
///
/// Returns: integer array for adjacency list
///
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

///
/// getID()
///
/// Generates a uuid and casts to string.
/// Uses Boost::uuid library
///
/// Return: uuid string
///
std::string InputParser::genID()
{
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	std::string stringID = boost::lexical_cast<std::string>(uuid);
	return stringID;
}

///
/// loadSaveFile()
///
/// If a save file is present, it loads the instance from savefile.
/// Currently only returns uuid for the instance.
/// Uses Boost library for serialization.
///
void InputParser::loadSaveFile()
{
	std::string filename = FILENAME;
	if(std::ifstream(filename + "-RegularRoom"))
	{
		RegularRoom* room;
		std::ifstream ifs(filename + "-RegularRoom");
		boost::archive::text_iarchive ar(ifs);
		ar & room;

		cout << "loaded successfully" << endl;
		mInstanceMap.insert(std::make_pair(room->getID(), room));
	}
	
	if(std::ifstream(filename + "-PuzzleRoom"))
	{
		PuzzleRoom* room;
		std::ifstream ifs(filename + "-PuzzleRoom");
		boost::archive::text_iarchive ar(ifs);
		ar & room;

		cout << "loaded successfully" << endl;
		mInstanceMap.insert(std::make_pair(room->getID(), room));
	}
	
}

///
/// getCommand()
///
/// Gathers user input and parses commands.
/// Valid actons are create, print, delete, and quit.
/// After creating an instance, it will prompt to save.
///
void InputParser::getCommand()
{
	MapPrototypeFactory* factory = NULL;

	while(true)
	{
		std::string action;
		
		std::cout << "enter command [create|print|delete|quit]" << std::endl;
		std::cin >> action;
		
		if(action == "quit")
		{
			break;
		}
		else if (action == "create")
		{
			std::string classname = getClassName();
			int adjList[4] = {0,0,0,0};

			if(classname == "RegularRoom")
			{
				RegularRoom* room = new RegularRoom(genID(), adjList);
				factory = new MapPrototypeFactory(room);
				mInstanceMap.insert(std::make_pair(room->getID(), room));

				std::string save = "";
				cout << "save? (y|n)" << endl;
				cin >> save;

				if(save == "y")
				{
					std::string filename = FILENAME;
					std::ofstream ofs(filename += "-RegularRoom");
					boost::archive::text_oarchive ar(ofs);
					ar & room;
				}
			}
			else if(classname == "PuzzleRoom")
			{
				PuzzleRoom* room = new PuzzleRoom(genID(), adjList);
				factory = new MapPrototypeFactory(room);
				mInstanceMap.insert(std::make_pair(room->getID(), room));

				std::string save = "";
				cout << "save? (y|n)" << endl;
				cin >> save;

				if(save == "y")
				{
					std::string filename = FILENAME;
					std::ofstream ofs(filename += "-PuzzleRoom");
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
			if(mInstanceMap.empty())
			{
				std::cout << "no instance" << std::endl;
			}
			else
			{
				//todo print all
				std::map<std::string, Room*>::iterator iter = mInstanceMap.begin();
				while (iter != mInstanceMap.end())
				{
					Room* room = iter->second;
					room->print();

					iter++;
				}
			}
		}
		else if (action == "delete")
		{
			if(mInstanceMap.empty())
			{
				std::cout << "no instance" << std::endl;
			}
			else
			{
				mInstanceMap.clear();
			}
		}
		else
		{
			std::cout << "invalid action" << std::endl;
		}
	}
}