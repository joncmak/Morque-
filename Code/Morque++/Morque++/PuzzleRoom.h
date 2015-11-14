#pragma once
#include "Room.h"

#include <iostream>
#include <string>

class PuzzleRoom :
	public Room
{
public:
	PuzzleRoom() : mID("0"), mAdjacencyList(0){}
	PuzzleRoom(std::string, int*);
	PuzzleRoom(const PuzzleRoom&);
	~PuzzleRoom(void) {};

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
        ar & boost::serialization::base_object<Room>(*this);
        ar & mID;
    }
};

