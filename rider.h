#ifndef _RIDER_H_
#define _RIDER_H_

#include "elevator.h"

class rider
{
private:
	int arrival_time; // what is the purpose of this? Do we plan on using the time of day the rider arrived?
	int selectFloor;
	int wait_time;
	int trip_time;
	int id_num;

public:	
	rider(int intarrival_time) {
		arrival_time = intarrival_time;
	}

	int get_arrival_time() { return arrival_time; }
	int get_selectFloor() { return selectFloor; }
	int get_wait_time() { return wait_time; }
	int get_trip_time() { return trip_time; }
	int get_id() { return id_num; }

	void set_arrival_time(int aTime) { arrival_time = aTime; }
	void set_selectFloor(int sFloor) { selectFloor = sFloor; }
	void set_wait_time(int wTime) { wait_time = wTime; }
	void set_trip_time(int tTime) { trip_time = tTime; }
	void set_id(int sID) { id_num = sID; }
};



#endif
