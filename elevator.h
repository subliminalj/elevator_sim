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
	bool goingup;
	std::list<rider> passenger_list; // list of passengers with their own destination
	std::list<rider> waiting_list; // list of passengers with their own destination
public:
	elevator()
	{
	}
	int get_floornum() { return floornum; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	int get_up() { return goingup; }
	std::list<rider> get_riders() { return passenger_list; }
	std::list<rider> get_waitint() { return waiting_list; }
	bool empty() { return passenger_list.empty(); }
	void update();
};


#endif
