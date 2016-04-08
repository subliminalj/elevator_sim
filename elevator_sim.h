#include "elevator.h"
//#include "rider.h"
//#include <iostream>
//#include <list>
using namespace std;

class elevator_sim
{
public:
	void elevator_sim::run_simulation(int initclock, elevator& simElev)
	{
		int numRiders = 1;
		int currentFloor = 1;
		bool goingUp = 1;
		int maxRiders = rand() % 20 + 1; // randomly determins the number of elevator requests that will be made for the program
		int maxLevel = rand() % 20 + 1;
		
		while (simElev.get_total_served() < maxRiders) // loops until all requests have been picked up and disembarked
		{
			rider newRider(clock, rand() % 20 + 1, rand() % 20 + 1, numRiders); //initializes a new rider
			if (numRiders == 1) // first rider is added on the first iteration of the loop
			{
				simElev.add_waiter(newRider, clock);
				numRiders++;
			}
			srand(clock); //resets rand based on clock value
			if ( rand() % 5 == 0 && numRiders <= maxRiders )//adds initialized rider only if randomizer matches 0 and the maxRider limit hasn't been reached, 
			{												//allowing the elevator to transverse floors without new riders being generated
				simElev.add_waiter(newRider, clock);	
				numRiders++;							
			}
			//if (simElev.get_waiting().front().get_current_floor() == simElev.get_floornum())
			//	simElev.add_rider(newRider, 2);
			simElev.update(simElev, clock);

			//checks if elevator direction needs to be changed
			if (simElev.get_floornum() == simElev.get_maxfloor()) // if currentfloor = maxfloor set going up to false
				simElev.set_up(false);
			else if (simElev.get_floornum() == simElev.get_minfloor() || simElev.get_floornum() == 1) // if currentfloor = minfloor set going up to true
				simElev.set_up(true);
			
			if (simElev.get_up() == false) // if going up is false go down one floor
				simElev.set_floornum(simElev.get_floornum() - 1);
			else
				simElev.set_floornum(simElev.get_floornum() + 1); // else go up one floor
			
			clock++;
		}
	}
	
	int get_clock() { return clock;}
	void elevator_sim::print_stats(list<rider>& disembark, elevator& elev)
	{
		cout << "The elevator ran for " << clock << " seconds." << endl;
		cout << "There were a total of " << elev.get_total_served() << " passengers." << endl;
		int averagewait = 0;
		int averageride = 0;
		list<rider>::iterator it = disembark.begin();
		//for loop of disembarked to total average wait and average ride
		for (it = disembark.begin(); it != disembark.end(); it++)
		{
			averagewait += it->get_wait_time();
			averageride += it->get_trip_time();
		}
//		averagewait /= disembark.size();
	//	averageride /= disembark.size();
		cout << "The average wait for each rider was " << averagewait << " seconds." << endl;
		cout << "The average ride for each rider was " << averageride << " seconds." << endl;
	}

private:
	int clock = 0;
	int total_time = 0;
	double rate = 0.2;
	Random randValue;
};

