#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_

#include <vector>
#include <queue>
#include "rider.h"
#include <iostream>
#include <list>

class elevator
{
private:
	int floornum;
	int maxfloor, minfloor;
	int total_served;
	double arrival_rate;
	std::list<rider> rider_list;
	std::list<rider> waiting_list;
	std::list<rider> disembarked;
public:
	elevator::elevator() {}
	elevator(int floors, double arrival)
	{
		maxfloor = floors;
		arrival_rate = arrival;
	}
	int get_floornum() { return floornum; }
	int get_maxfloor() { return maxfloor; }
	int get_minfloor() { return minfloor; }
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
	void update(list<rider>& waiting, list<rider>& rider, list<rider>& disembark, elevator& elev);

	void elevator::add_rider(rider& newrider, int initTime) // called when adding new passengers
	{
		list<rider>::iterator it = rider_list.begin(); // init it
		maxfloor = newrider.get_destination();
		minfloor = newrider.get_destination();

		for (it = rider_list.begin(); it != rider_list.end(); it++)
		{
			if (it->get_destination() > newrider.get_destination()) // as we go through the list we look for the first object that has a higher floor number than our rider or an empty list item 
			{
				rider_list.insert(it, newrider); // insert rider in order -- double check this sort
				newrider.start_trip_timer(initTime);
			}
			if (it->get_destination() > maxfloor)
				maxfloor = it->get_destination();
			if (it->get_destination() < minfloor)
				minfloor = it->get_destination();
		}
	}
	void elevator::add_waiter(rider& newrider) // called when adding new passengers
	{
		list<rider>::iterator it = waiting_list.begin(); // init it
		maxfloor = newrider.get_destination();
		minfloor = newrider.get_destination();

		for (it = waiting_list.begin(); it != waiting_list.end(); it++)
		{
			waiting_list.push_back(newrider);
			newrider.start_wait_time(initTime);
		}
		if (it->get_destination() > maxfloor)
			maxfloor = it->get_destination();
		if (it->get_destination() < minfloor)
			minfloor = it->get_destination();
	}


	void elevator::update(elevator& elev, clock)
	{
		//PICK UP PASSENGERS
		list<rider>::iterator it = waiting_list.begin(); // init waiting list it
		for (it = waiting_list.begin(); it != waiting_list.end(); it++) // cycle through waiting list
		{
			if (elev.get_floornum() == it->get_current_floor() && elev.get_up() == it->get_up()) // if elevator is on a floor where someone is waiting and they are headed in the direction of the elevator, pick them up
			{
				elev.add_rider(*it)
				it->stop_wait_timer(currTime);
				it->start_trip_timer(currTime);
			}
		}
		//UPDATE FLOOR FOR RIDERS -- this may not be neccessary
		list<rider>::iterator it = rider_list.begin();
		for (it = rider_list.begin(); it != rider_list.end(); it++) // cycle through passenger list
		{
			it->set_current_floor(elev.get_floornum()); // set all passengers current floor to the floor the elevator is on
		}
		//DISEMBARK
		list<rider>::iterator it = rider_list.begin();
		for (it = rider_list.begin(); it != rider_list.end(); it++) // cycle through passenger list
		{
			if (elev.get_floornum() == it->get_destination()) // if elev floornum == rider destination
			{
				it->stop_trip_timer(currTime);
				disembarked.push_back(it*); // add rider to disembarked list
				rider_list.erase(it); // erase rider from passenger list
				elev.add_total_served(); // add 1 to total served
			}
		}
	}

	/*void elevator::update_wait_timer(list<rider>& waitingRiderList, int floorDiff, int speed)
	{
		list<rider>::iterator witer;
		for (witer = waitingRiderList.begin(); witer != waitingRiderList.end(); witer++)
			witer->total_wait_timer(floorDiff*speed);
	}

	void elevator::update_trip_timer(list<rider>& tripRiderList, int floorDiff, int speed)
	{
		list<rider>::iterator titer;
		for (titer = tripRiderList.begin(); titer != tripRiderList.end(); titer++)
			titer->total_trip_timer(floorDiff*speed);
	}*/
}

#endif
