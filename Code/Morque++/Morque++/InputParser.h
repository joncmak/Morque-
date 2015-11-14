#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast/lexical_cast_old.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "MapPrototypeFactory.h"

///
/// Input Command Parser
/// 
/// Parses user input. Gathers user input using cin.
/// Auto-generates uuid for insteance IDs.
/// Loads Room instance if savefile is present.
/// Requires Boost C++ Library
///
class InputParser
{
public:
	InputParser() {};
	~InputParser() {};
	void getCommand();
	void loadSaveFile();

private:
	std::string getClassName();
	int* getAdjList();
	std::string genID();
};

