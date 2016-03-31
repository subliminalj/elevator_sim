#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_
#include <vector>
#include <queue>
#include "rider.h"
#include "floors.h"
#include <iostream>
#include <list>

class elevator
{
private:
	int floornum;
	bool elevDirection;
	int speed;  //how will we be using the speed? Won't that be constant?
	int runID;
	int total_served;
	double arrival_rate;
	std::list<elevator> destination; // needs to be an elevator object to utilize the direction
	//std::list<rider> rider_list;
	std::list<floors> individual_floors; //so are the elevators supposed to have pointers to this constant list of floors? If so, wouldn't this be better as a vector?

public:
	elevator(floors, int, int);
	elevator(int, int, int);
	int get_floornum() { return floornum; }
	int get_speed() { return speed; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	std::list<elevator> get_dest() { return destination; }
	std::list<rider> get_riders() { return rider_list; }
	std::list<floors> get_floors() { return individual_floors; }
	bool empty() { return destination.empty(); }
	void add_rider(elevator&);
	void rider_destination();
};


#endif
