#pragma once
#include <string>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast/lexical_cast_old.hpp>

///
/// Prototype for Room classes
/// 
/// Base class for RegularRoom, PuzzleRoom, and TrapRoom
/// Requires Boost C++ Library
///
class Room
{
	friend class boost::serialization::access;

	std::string mID;
	int* mAdjacencyList;

	// Boost::Serialization
	template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & mID;
    }

public:
	Room() {};
	~Room() {};
	virtual Room* clone()=0;
	virtual void print()=0;
};

