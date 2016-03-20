#ifndef _RIDER_H_
#define _RIDER_H_

class rider
{
private:
	int arrival_time;
	int destination;
	int wait_time;
	int trip_time;
	int id_num;

public:	
	int get_arrival_time() { return arrival_time; }
	int get_destination() { return destination; }
	int get_wait_time() { return wait_time; }
	int get_id() { return id_num; }


};

rider::rider(int arrival_time);

#endif
