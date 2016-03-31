#include "elevator.h"

using namespace std;

elevator::elevator(floors floorSelect, int intspeed, int id) 
{
	floornum = floorSelect.floornumber; //originally just said floors. Is this what you meant?
	elevDirection = floorSelect.direction;
	speed = intspeed;
	runID = ++id;
}

elevator::elevator(int floorSelect, int intspeed, int id)
{
	floornum = floorSelect; //originally just said floors. Is this what you meant?
	elevDirection = floorSelect > destination.begin()->floornum;
	speed = intspeed;
	runID = id;
}

void elevator::add_rider(elevator& newFloor)
{
	list<elevator>::iterator iter = destination.begin();

	if (newFloor.elevDirection == 0)
		return;

	while (newFloor.elevDirection != iter->elevDirection)
		iter++;

	for (iter; iter != destination.end(); iter++)
	{
		if ((newFloor.elevDirection && newFloor.floornum < iter->floornum)
			|| (!newFloor.elevDirection && newFloor.floornum > iter->floornum))
		{
			destination.insert(iter, newFloor);
			break;
		}

	}
}

void elevator::rider_destination()
{
	destination.pop_front();
}