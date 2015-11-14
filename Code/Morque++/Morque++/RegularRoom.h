#pragma once
#include "Room.h"

#include <iostream>
#include <string>

class RegularRoom : 
	public Room
{
public:
	RegularRoom() : mID("0"), mAdjacencyList(0){}
	RegularRoom(std::string, int*);
	RegularRoom(const RegularRoom&);
	~RegularRoom() {};

	Room* clone();
	void print();
	std::string printAdjList();

private:
	friend class boost::serialization::access;

	std::string mID;
	int* mAdjacencyList;
	void setAdjacencyList(int*);

	template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        //ar & boost::serialization::base_object<Room>(*this);
        ar & mID;
    }
};