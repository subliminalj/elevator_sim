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
	int total_served;
	double arrival_rate;
	std::list<rider> rider_list;
	std::list<rider> waiting_list;

public:
	elevator();
	elevator();
	int get_floornum() { return floornum; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	std::list<rider> get_riders() { return rider_list; }
	std::list<rider> get_waiting() { return waiting_list; }
	bool empty() { return rider_list.empty(); }
};


#endif
