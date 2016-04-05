#include "elevator.h"
#include "rider.h"
#include <iostream>
#include <list>

class elevator_sim
{
public:
	elevator_sim();

	void run_simulation()
	{
		int numRiders = 1;
		int currTime = 0;
		int maxRiders = randValue.next_int(20);
		int maxLevel = randValue.next_int(20) + 1;
		elevator simElev(maxLevel, 0.2);
		
		while (numRiders <= maxRiders)
		{
			if (randValue.next_double(0.2) == 0)
			{
				rider eleRider(currTime, randValue.next_int(maxLevel) + 1, randValue.next_int(maxLevel) + 1, numRiders, simElev);
				numRiders++;
			}


			currTime++;
			
		}
	};
	void print_stats(std::list<rider>& disembarked);
	int get_clock() { return clock;}

private:
	int clock;
	int total_time;
	double rate = 0.2;
	Random randValue;
};

void elevator_sim::run_simulation(int initclock, elevator& elev) 
{
	clock = initclock;
	

}

void elevator_sim::print_stats(std::list<rider>& disembarked, elevator& elev)
{
	cout << "The elevator ran for " << total_time / 60 << " minutes." << endl;
	cout << "There were a total of " << elev.get_total_served() << " passengers." << endl;
	int averagewait;
	int averageride;
	list<rider>::iterator it = disembarked.begin();
	//for loop of disembarked to total average wait and average ride
	for (it = disembarked.begin(); it != disembarked.end(); it++)
}
