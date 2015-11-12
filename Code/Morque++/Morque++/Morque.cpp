#include <iostream>
#include <string>

#include "MapPrototypeFactory.h"

using namespace std;

#define WALL 0
#define DOOR 1

string getClassName()
{
	string classname = "";
	cout << "enter classname" << endl;
	cin >> classname;
	return (classname == "RegularRoom" || classname == "PuzzleRoom") ? classname: "";
}

int* getAdjList()
{
	int inAdjList = 0;
	int* adjList = new int[4];
	
	cout << "enter adj list " << endl;
	int index;
	for(index=0; index< 4; index++)
	{
		cout << index << ": " << endl;
		cin >> inAdjList;
		 
		adjList[index] = (inAdjList == WALL || inAdjList == DOOR) ? inAdjList : -1;
	}
	return adjList;
}

int main()
{
	int id = 0;
	MapPrototypeFactory* factory = NULL;

	while(true)
	{
		string action;
		cout << "enter command [create|print|quit]" << endl;
		cin >> action;
		
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
				factory = new MapPrototypeFactory(new RegularRoom(id++, adjList));
			}
			else if(classname == "PuzzleRoom")
			{
				factory = new MapPrototypeFactory(new PuzzleRoom(id++, adjList));
			}
			else
			{
				cout << "invalid classname" << endl;
			}
		}
		else if (action == "print")
		{
			if(NULL == factory)
			{
				cout << "no instance" << endl;
			}
			else
			{
				Room* room = factory->getRoom();
				room->print();
			}
		}
		else
		{
			cout << "invalid action" << endl;
		}
	}

	system("pause");
	return 0;
}
