#pragma once

class Room
{
public:
	Room() {};
	virtual ~Room() {};
	virtual Room* clone()=0;
	virtual void print()=0;
};

