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
	rider(int arrival_time, int destination, int current_floor, int id_num, elevator& elev) {
		if (current_floor < destination)
		{
			goingup = true;
		}
		if (current_floor == destination)
		{
			//re randomize destination
		}
		start_wait_timer(); // start the waiting timer
		arrival_time = elev.get_clock();
	}

	int get_arrival_time() { return arrival_time; }
	int get_destination() { return destination; }
	int get_current_floor() { return current_floor; }
	bool get_up() { return goingup; }
	int get_wait_time() { return wait_time; }
	int get_trip_time() { return trip_time; }
	int get_id() { return id_num; }
	void set_current_floor(int floor) {	current_floor = floor; }
	void start_wait_timer() {}//start the timer for waiting
	void start_trip_timer(){} // start the timer for the elevator ride
	void stop_wait_timer() {} // stop the wait timer when the wait is over - rider pickup
	void stop_trip_timer() {} // stop the trip timer when arrived at destination

};



#endif
