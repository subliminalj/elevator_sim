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
	elevator(int floors, double arrival) {
		floornum = floors;
		arrival_rate = arrival;
	}
		
		
	int get_floornum() { return floornum; }
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


};


#endif
