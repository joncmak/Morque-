#include "room.h"
class NormalRoom :
	public Room
{
public:
	NormalRoom();
	NormalRoom(int, int*);
	NormalRoom(const NormalRoom& pNormalRoom);
	~NormalRoom();

	virtual void init()=0;
	virtual Room* clone()=0;
	virtual void print()=0;

private:
	int mID;
	int* mAdjacencyList;
	virtual void setAdjacencyList(int*);
};

