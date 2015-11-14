#include "Orque.h"

#define WALL 0
#define DOOR 1

string getClassName()
{
	string classname = "";
	std::cout << "enter classname" << std::endl;
	std::cin >> classname;
	return (classname == "RegularRoom" || classname == "PuzzleRoom" || "TrapRoom") ? classname: "";
}

int* getAdjList()
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

string genID()
{
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	std::string stringID = boost::lexical_cast<std::string>(uuid);
	return stringID;
}

int main()
{
	int id = 0;
	MapPrototypeFactory* factory = NULL;
	Orque orque;

	while(true)
	{
		string action;
		
		std::cout << "enter command [create|print|quit]" << std::endl;
		std::cin >> action;
		
		if(action == "quit")
		{
			break;
		}
		else if (action == "create")
		{
			string classname = getClassName();
			int* adjList = getAdjList();

			if(classname == "RegularRoom")
			{
				factory = new MapPrototypeFactory(new RegularRoom(genID(), adjList));
			}
			else if(classname == "PuzzleRoom")
			{
				factory = new MapPrototypeFactory(new PuzzleRoom(genID(), adjList));
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
				Room* room = factory->getRoom();
				room->print();
			}
		}
		else
		{
			std::cout << "invalid action" << std::endl;
		}
	}

	system("pause");
	return 0;
}