#ifndef _RIDER_H_
#define _RIDER_H_

#include "Random.h"
//#include "elevator_sim.h"
//#include "elevator.h"

class rider
{
private:
	int arrival_time, trip_start_time;
	int destination;
	int current_floor;
	Random randomVal;
	bool goingup;
	int wait_time;
	int trip_time;
	int id_num;

public:	
	rider() {};
	rider(int a_time, int dest, int cfloor, int id){
		goingup = current_floor < destination;
		//arrival_time = a_time;
		destination = dest;
		current_floor = cfloor;
		id_num = id;
		while (current_floor == destination)
			destination = randomVal.next_int(20) + 1;
		//start_wait_timer(arrival_time); // start the waiting timer	
	}

	int get_arrival_time() { return arrival_time; }
	int get_destination() { return destination; }
	int get_current_floor() { return current_floor; }
	bool get_up() { return goingup; }
	int get_trip_time() { return trip_time; }
	int get_id() { return id_num; }
	void set_current_floor(int floor) {	current_floor = floor; }
	void start_wait_timer(int start_wait) { arrival_time = start_wait; }
	void start_trip_timer(int start_trip) { trip_start_time = start_trip; }
	void stop_wait_timer(int stop_wait) { wait_time = stop_wait - arrival_time; } // stop the wait timer when the wait is over - rider pickup
	void stop_trip_timer(int stop_trip) { trip_time = stop_trip - trip_start_time; } // stop the trip timer when arrived at destination
	int get_wait_time() { return wait_time; }
};



#endif
