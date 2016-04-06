#ifndef _RIDER_H_
#define _RIDER_H_

#include "Random.h"

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
	rider(int arrival_time, int destination, int current_floor, int id_num, elevator& elev) {
		if (current_floor < destination)
		{
			goingup = true;
		}
		while (current_floor == destination)
			destination = randomVal.next_int(20) + 1;

		start_wait_timer(); // start the waiting timer
		//arrival_time = sim.get_clock();
	}

	int get_arrival_time() { return arrival_time; }
	int get_destination() { return destination; }
	int get_current_floor() { return current_floor; }
	bool get_up() { return goingup; }
	int get_wait_time() { return wait_time; }
	int get_trip_time() { return trip_time; }
	int get_id() { return id_num; }
	void set_current_floor(int floor) {	current_floor = floor; }
	//void total_wait_timer(int wTime){ wait_time += wTime; } // start the timer for waiting
	//void total_trip_timer(int tTime) { trip_time += tTime; } // start the timer for the elevator ride
	void stop_wait_timer(int stop_wait) { wait_time = stop_wait - arrival_time; } // stop the wait timer when the wait is over - rider pickup
	void stop_trip_timer(int stop_trip) { trip_time = stop_trip - trip_start_time; } // stop the trip timer when arrived at destination
	void start_wait_timer(int start_wait) { arrival_time = start_wait; }
	void start_trip_timer(int start_trip) { trip_start_time = start_trip; }
};



#endif
