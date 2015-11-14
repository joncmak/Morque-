#include "InputParser.h"

int main()
{
	InputParser* input = new InputParser();

	input->loadSaveFile();
	//Get input
	input->getCommand();

	system("pause");
	return 0;
}