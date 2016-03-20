#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_
#include <queue>
#include "rider.h"
#include <iostream>
#include <list>

class elevator
{
private:
	int floors;
	int speed;
	int total_served;
	double arrival_rate;
	std::queue<int> destination_q;
	std::list<rider> passenger_list;

public:
	int get_floors() { return floors; }
	int get_speed() { return speed; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	std::queue<int> get_queue() { return destination_q; }
	std::list<rider> get_riders() { return passenger_list; }
	bool empty() { return destination_q.empty(); }


};


elevator::elevator();


#endif
