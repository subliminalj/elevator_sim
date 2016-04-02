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
	int maxfloor;
	int total_served;
	double arrival_rate;
	std::list<rider> rider_list;
	std::list<rider> waiting_list;

public:
	elevator(int floors, double arrival) {
		maxfloor = floors;
		arrival_rate = arrival;
	}
		
		
	int get_floornum() { return floornum; }
	int get_maxfloor() { return maxfloor; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	std::list<rider> get_riders() { return rider_list; }
	std::list<rider> get_waiting() { return waiting_list; }
	void set_floornum(int floor) { floornum = floor; }
	void add_total_served() { total_served++; }
	void set_arrival_rate(double arrive) { arrival_rate = arrive; }
	void set_riders(std::list<rider> riders) { rider_list = riders; }
	void set_waiting(std::list<rider> waiting) { waiting_list = waiting; }
	bool empty() { return rider_list.empty(); }
	update() {}
	void elevator::add_rider(rider& newrider)
	{
		list<rider>::iterator it = rider_list.begin(); // init it

		for (it = rider_list.begin(); it != rider_list; it++)
		{
			if (it->get_destination < newrider.get_destination || it->get_destination == NULL) // as we go through the list we look for the first object that has a higher floor number than our rider or an empty list item 
				rider_list.insert(it, newrider) // insert rider in order
		}
	}

	void elevator::rider_destination(rider& rider)
	{
		if (rider.get_up && rider.get_destination == shaft1.floornum && shaft1.get_up) // shaft1 was created as an elevator object in main, there may be a problem with this code.
			rider_list.pop_front();

		if (!rider.get_up)
			rider_list.pop_back();

	}




};


#endif
