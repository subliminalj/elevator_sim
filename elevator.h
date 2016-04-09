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
	int floornum = 1;
	int maxfloor, minfloor;
	int total_served = 0;
	double arrival_rate;
	bool goingup = 1;
	std::list<rider> rider_list;
	std::list<rider> waiting_list;
	std::list<rider> disembarked;
public:
	elevator::elevator() {}
	elevator(int floors, double arrival, std::list<rider> riders, std::list<rider> waiting,	std::list<rider> disembark)
	{
		maxfloor = floors;
		minfloor = 1;
		arrival_rate = arrival;
		rider_list = riders;
		waiting_list = waiting;
		disembarked = disembark;
	}
	int get_floornum() { return floornum; }
	int get_maxfloor() { return maxfloor; }
	int get_minfloor() { return minfloor; }
	int get_total_served() { return total_served; }
	double get_arrival_rate() { return arrival_rate; }
	bool get_up() { return goingup; }
	std::list<rider> get_riders() { return rider_list; }
	std::list<rider> get_waiting() { return waiting_list; }
	std::list<rider> get_disembarked() { return disembarked; }
	void set_floornum(int floor) { floornum = floor; }
	void set_up(bool up) { goingup = up; }
	void add_total_served() { total_served+=1; }
	void set_arrival_rate(double arrive) { arrival_rate = arrive; }
	void set_riders(std::list<rider> riders) { rider_list = riders; }
	void set_waiting(std::list<rider> waiting) { waiting_list = waiting; }
	void set_disembarked(std::list<rider> dis) { disembarked = dis; }
	bool empty() { return rider_list.empty(); }
	void add_rider(rider&, int);
	void add_waiter(rider&, int);
	void update(elevator&, int);
};
	void elevator::add_rider(rider& newrider, int rTime) // called when adding new passengers
	{
		std::list<rider>::iterator r_addit = rider_list.begin(); // init it
		maxfloor = newrider.get_destination();
		minfloor = newrider.get_destination();

		//adds rider w/o sorting if list is empty
		if (rider_list.empty())
		{
			rider_list.push_back(newrider); 
			return;
		}
		for (r_addit = rider_list.begin(); r_addit != rider_list.end(); r_addit++)
		{
			if (r_addit->get_destination() > newrider.get_destination()) // as we go through the list we look for the first object that has a higher floor number than our rider 
			{
				rider_list.insert(r_addit, newrider); // insert rider in order
				newrider.stop_wait_timer(rTime);
				newrider.start_trip_timer(rTime);
			}
			if (r_addit->get_destination() > maxfloor)
				maxfloor = r_addit->get_destination();
			if (r_addit->get_destination() < minfloor)
				minfloor = r_addit->get_destination();

			std::cout << "RIDER: "<< maxfloor << " <max min> " << minfloor << std::endl;
		}
		//add_total_served();
		//std::cout << get_total_served() <<" " << get_up() << std::endl; // TEMPORARY. Just adding total served here for debugging
	}
	void elevator::add_waiter(rider& newrider, int wTime) // called when adding new passengers
	{
		waiting_list.push_back(newrider); // add rider to waiting list
		newrider.start_wait_timer(wTime);  // start timer
		std::cout << newrider.get_destination() << " _ " << newrider.get_current_floor() << std::endl; // output destination and current floor
		if (newrider.get_destination() > maxfloor) // if rider is going higher than the max floor
			maxfloor = newrider.get_destination(); // set maxfloor to the destination
		if (newrider.get_destination() < minfloor) // if rider is going lower than the min floor
			minfloor = newrider.get_destination(); // set minfloor to the destination
		std::cout << "WAITER: " << maxfloor << " <max min> " << minfloor << std::endl; // output
	}


	void elevator::update(elevator& elev, int clock)
	{
		//PICK UP PASSENGERS
		std::list<rider>::iterator wit = waiting_list.begin(); // init waiting list it

		for (wit = waiting_list.begin(); wit != waiting_list.end(); wit++) // cycle through waiting list
		{
			if (get_floornum() == wit->get_current_floor() && get_up() == wit->get_up()) // if elevator is on a floor where someone is waiting and they are headed in the direction of the elevator, pick them up
			{
				add_rider(*wit, clock); // add rider from waiting list to rider list
				wit->stop_wait_timer(clock); // stop wait timer
				wit = waiting_list.erase(wit); // erase the rider from the waiting list
				break;
			}
		}
		//UPDATE FLOOR FOR RIDERS
		std::list<rider>::iterator rit = rider_list.begin();
		for (rit = rider_list.begin(); rit != rider_list.end(); rit++) // cycle through passenger list
		{
			rit->set_current_floor(elev.get_floornum()); // set all passengers current floor to the floor the elevator is on
		}
		//DISEMBARK
		std::list<rider>::iterator rit2 = rider_list.begin();
		for (rit2 = rider_list.begin(); rit2 != rider_list.end(); rit2++) // cycle through passenger list
		{
			if (elev.get_floornum() == rit2->get_destination()) // if elev floornum == rider destination
			{
				rit2->stop_trip_timer(clock);
				disembarked.push_back(*rit2); // add rider to disembarked list
				rit2 = rider_list.erase(rit2); // erase rider from passenger list
				add_total_served(); // add 1 to total served
				break;
			}
		}
	}


#endif
