#pragma once
#include <string>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

class Room
{
	friend class boost::serialization::access;

	std::string mID;
	int* mAdjacencyList;

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

