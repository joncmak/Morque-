#pragma once
#include "Room.h"

#include <iostream>
#include <string>

///
/// Basic Regular Room class
/// 
/// Uses Room() Base Class
/// Requires Boost C++ Library
///
class RegularRoom : 
	public Room
{
public:

	// Default Constructor
	RegularRoom() : mID("0"), mAdjacencyList(0){}

	// Copy Constructor
	RegularRoom(std::string, int*);
	RegularRoom(const RegularRoom&);
	~RegularRoom() {};

	Room* clone();
	void print();
	std::string printAdjList();
	std::string getID()
	{
		return mID;
	}

	int* getAdjacencyList()
	{
		return mAdjacencyList;
	}

private:
	friend class boost::serialization::access;

	std::string mID;
	int* mAdjacencyList;
	void setAdjacencyList(int*);

	// Boost::Serialization
	template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & mID;
    }
};