#include <iostream>
#include <string>

#include "RegularRoom.h"
#include "MapPrototypeFactory.h"

using namespace std;

int main()
{
	string inputClass = "";

	std::cout << "hello world" << endl;
	std::cin >> inputClass;
	std::cout << "you entered " << inputClass << endl;

	int adjacencyList[4] = {0, 0, 0, 0};
	RegularRoom *room1 = new RegularRoom(0, adjacencyList);

	system("pause");
	return 0;
}
