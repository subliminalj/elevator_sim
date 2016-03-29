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
	int speed;
	int total_served;
	double arrival_rate;
	std::vector<int> destination_vec;
	std::list<rider> passenger_list;
	std::list<floors> individual_floors;

public:
	elevator(int intfloors, int intspeed) { 
		floors = intfloors;
		speed = intspeed;
	}
	int get_floornum() { return floornum; }
	int get_speed() { return speed; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	std::vector<int> get_dest() { return destination_vec; }
	std::list<rider> get_riders() { return passenger_list; }
	std::list<floors> get_floors() { return individual_floors; }
	bool empty() { return destination_vec.empty(); }


};


#endif
