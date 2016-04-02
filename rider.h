#ifndef _RIDER_H_
#define _RIDER_H_

#include "elevator.h"

class rider
{
private:
	int arrival_time;
	int destination;
	int current_floor;
	bool goingup;
	int wait_time;
	int trip_time;
	int id_num;

public:	
	rider(int arrival_time, int destination, int current_floor, bool goingup, int id_num) {
		
	}

	int get_arrival_time() { return arrival_time; }
	int get_destination() { return destination; }
	int get_current_floor() { return current_floor; }
	bool get_up() { return goingup; }
	int get_wait_time() { return wait_time; }
	int get_trip_time() { return trip_time; }
	int get_id() { return id_num; }



};



#endif
