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
	void add_rider(rider&, int);
	void add_waiter(rider&, int);
	void update(elevator&, int);
};
	void elevator::add_rider(rider& newrider, int initTime) // called when adding new passengers
	{
		std::list<rider>::iterator r_addit = rider_list.begin(); // init it
		maxfloor = newrider.get_destination();
		minfloor = newrider.get_destination();

		for (r_addit = rider_list.begin(); r_addit != rider_list.end(); r_addit++)
		{
			if (r_addit->get_destination() > newrider.get_destination()) // as we go through the list we look for the first object that has a higher floor number than our rider or an empty list item 
			{
				rider_list.insert(r_addit, newrider); // insert rider in order -- double check this sort
				newrider.start_trip_timer(initTime);
			}
			if (r_addit->get_destination() > maxfloor)
				maxfloor = r_addit->get_destination();
			if (r_addit->get_destination() < minfloor)
				minfloor = r_addit->get_destination();
		}
	}
	void elevator::add_waiter(rider& newrider, int initTime) // called when adding new passengers
	{
		std::list<rider>::iterator w_addit = waiting_list.begin(); // init it
		maxfloor = newrider.get_destination();
		minfloor = newrider.get_destination();

		for (w_addit = waiting_list.begin(); w_addit != waiting_list.end(); w_addit++)
		{
			waiting_list.push_back(newrider);
			newrider.start_wait_timer(initTime);
		}
		if (w_addit->get_destination() > maxfloor)
			maxfloor = w_addit->get_destination();
		if (w_addit->get_destination() < minfloor)
			minfloor = w_addit->get_destination();
	}


	void elevator::update(elevator& elev, int clock)
	{
		//PICK UP PASSENGERS
		std::list<rider>::iterator wit = waiting_list.begin(); // init waiting list it
		for (wit = waiting_list.begin(); wit != waiting_list.end(); wit++) // cycle through waiting list
		{
			if (elev.get_floornum() == wit->get_current_floor() && elev.get_up() == wit->get_up()) // if elevator is on a floor where someone is waiting and they are headed in the direction of the elevator, pick them up
			{
				elev.add_rider(*wit, clock);
				wit->stop_wait_timer(clock);
				wit->start_trip_timer(clock);
			}
		}
		//UPDATE FLOOR FOR RIDERS -- this may not be neccessary
		std::list<rider>::iterator rit = rider_list.begin();
		for (rit = rider_list.begin(); rit != rider_list.end(); rit++) // cycle through passenger list
		{
			rit->set_current_floor(elev.get_floornum()); // set all passengers current floor to the floor the elevator is on
		}
		//DISEMBARK
		std::list<rider>::iterator rit = rider_list.begin();
		for (rit = rider_list.begin(); rit != rider_list.end(); rit++) // cycle through passenger list
		{
			if (elev.get_floornum() == rit->get_destination()) // if elev floornum == rider destination
			{
				rit->stop_trip_timer(clock);
				disembarked.push_back(*rit); // add rider to disembarked list
				rider_list.erase(rit); // erase rider from passenger list
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

#endif
