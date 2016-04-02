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
	std::list<rider> disembarked;
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
	std::list<rider> get_disembarked() { return disembarked; }
	void set_floornum(int floor) { floornum = floor; }
	void add_total_served() { total_served++; }
	void set_arrival_rate(double arrive) { arrival_rate = arrive; }
	void set_riders(std::list<rider> riders) { rider_list = riders; }
	void set_waiting(std::list<rider> waiting) { waiting_list = waiting; }
	void set_disembarked(std::list<rider> dis) { disembarked = dis; }
	bool empty() { return rider_list.empty(); }
	update() {}
	
	void elevator::add_rider(rider& newrider)
	{
		list<rider>::iterator it = rider_list.begin(); // init it

		for (it = rider_list.begin(); it != rider_list; it++)
		{
			if (it->get_destination > newrider.get_destination || it->get_destination == NULL) // as we go through the list we look for the first object that has a higher floor number than our rider or an empty list item 
				rider_list.insert(it, newrider) // insert rider in order
		}
	}

	void elevator::rider_destination(rider& thisrider)
	{
		if (thisrider.get_destination() == shaft1.floornum) // if the rider is at their destination
			disembarked.push_back(thisrider) // add rider to list of served riders
			rider_list.delete(thisrider); // remove rider from passenger list
	}




};


#endif
