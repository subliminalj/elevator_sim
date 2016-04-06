#include "elevator.h"
#include "rider.h"
#include <iostream>
#include <list>
using namespace std;

class elevator_sim
{
public:
	void run_simulation(int initclock, elevator& simElev)
	{
		int numRiders = 1;
		int currTime = initclock;
		int maxRiders = randValue.next_int(20);
		int maxLevel = randValue.next_int(20) + 1;

		while (numRiders <= maxRiders)
		{
			if (randValue.next_double(0.2) == 0)
			{
				rider eleRider(currTime, randValue.next_int(maxLevel) + 1, randValue.next_int(maxLevel) + 1, numRiders, simElev);
				numRiders++;
			}


			clock++;
			numRiders++;
		}

	}
	
	int get_clock() { return clock;}
	void elevator_sim::print_stats(list<rider>& disembarked, elevator& elev)
	{
		cout << "The elevator ran for " << total_time / 60 << " minutes." << endl;
		cout << "There were a total of " << elev.get_total_served() << " passengers." << endl;
		int averagewait;
		int averageride;
		list<rider>::iterator it = disembarked.begin();
		//for loop of disembarked to total average wait and average ride
		for (it = disembarked.begin(); it != disembarked.end(); it++)
		{
			averagewait += it->get_wait_time();
			averageride += it->get_trip_time();
		}
		averagewait /= disembarked.size();
		averageride /= disembarked.size();
		cout << "The average wait for each rider was " << averagewait / 60 << " minutes." << endl;
		cout << "The average ride for each rider was " << averageride << " seconds." << endl;
	}

private:
	int clock;
	int total_time;
	double rate = 0.2;
	Random randValue;
};

