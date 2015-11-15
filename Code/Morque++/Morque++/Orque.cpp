#include "InputParser.h"

int main()
{
	InputParser* input = new InputParser();

	if(std::ifstream("savefile-RegularRoom") || std::ifstream("savefile-PuzzleRoom"))
	{
		input->loadSaveFile();
	}
	//Get input
	input->getCommand();

	system("pause");
	return 0;
}