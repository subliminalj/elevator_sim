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
		//int currentFloor = 1;
		bool goingUp = 1;
		int maxRiders = rand() % 20 + 1;
		int maxLevel = rand() % 20 + 1;
	
		//program starts when a rider requests an elevator. Begins on bottom (1st) floor
		rider riders[50];
		riders[numRiders - 1]={ clock, rand() % 20 + 1, 1, numRiders };
		simElev.add_waiter(riders[numRiders-1], clock);

		while (numRiders < maxRiders)
		{
			clock++;
			srand(clock);

			if ( rand()%5 == 1)
			{
				numRiders++;
				rand() % 20 + 1;
				riders[numRiders - 1] = { clock, rand()%20 + 1, rand() % 20 + 1, numRiders };
				simElev.add_waiter(riders[numRiders - 1], clock);
			}
			if (riders[numRiders - 1].get_destination() == simElev.get_floornum())
				simElev.add_rider(riders[numRiders - 1], 2);
			simElev.update(simElev, clock);

			if (simElev.get_floornum() == simElev.get_maxfloor())
				goingUp = 0;
			else if (simElev.get_floornum() == simElev.get_minfloor())
				goingUp = 1;

			if (goingUp == 0)
				simElev.set_floornum(simElev.get_floornum()-1);
			else
				simElev.set_floornum(simElev.get_floornum() +1);
		}
		simElev.update(simElev, clock);

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

