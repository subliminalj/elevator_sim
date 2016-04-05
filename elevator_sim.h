#include "elevator.h"
#include "rider.h"
#include <iostream>
#include <list>

using namespace std;

class elevator_sim
{
private:
	int clock;
	int total_time;

public:
	elevator_sim::elevator_sim() {}
	int get_clock() { return clock; }

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
			//calc average wait and average ride
		}
	}

	void elevator_sim::run_simulation(int initclock, elevator& elev)
	{
		clock = initclock;


	}



};

