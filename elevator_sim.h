#include "elevator.h"
#include "rider.h"
#include <iostream>
#include <list>
using namespace std;

class elevator_sim
{
public:
	void elevator_sim::run_simulation(int initclock, elevator& simElev)
	{
		int numRiders = 1;
		int currentFloor = 1;
		bool goingUp = 1;
		int maxRiders = randValue.next_int(20);
		int maxLevel = randValue.next_int(20) + 1;

		//program starts when a rider requests an elevator
		rider eleRider(0, randValue.next_int(maxLevel) + 1, randValue.next_int(maxLevel) + 1, numRiders);
		simElev.add_rider(eleRider, clock);

		while (numRiders <= maxRiders)
		{
			clock++;
			if (randValue.next_double(0.2) == 0)
			{
				numRiders++;
				rider eleRider(clock, randValue.next_int(maxLevel) + 1, randValue.next_int(maxLevel) + 1, numRiders);
				simElev.add_waiter(eleRider, clock);
			}

			simElev.update(simElev, clock);

			if (currentFloor == simElev.get_maxfloor())
				goingUp = 0;
			else if (currentFloor == simElev.get_minfloor())
				goingUp = 1;

			if (goingUp = 0)
				currentFloor--;
			else
				currentFloor++;
			//clock++;
		}

		simElev.update(simElev, clock);

	}
	
	int get_clock() { return clock;}
	void elevator_sim::print_stats(list<rider>& disembark, elevator& elev)
	{
		cout << "The elevator ran for " << total_time / 60 << " minutes." << endl;
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
		averagewait /= disembark.size();
		averageride /= disembark.size();
		cout << "The average wait for each rider was " << averagewait / 60 << " minutes." << endl;
		cout << "The average ride for each rider was " << averageride << " seconds." << endl;
	}

private:
	int clock;
	int total_time;
	double rate = 0.2;
	Random randValue;
};

