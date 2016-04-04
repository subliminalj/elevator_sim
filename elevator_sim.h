#include "elevator.h"
#include "rider.h"
#include <iostream>
#include <list>
class elevator_sim
{
public:
	elevator_sim();

	void run_simulation(int initclock);
	void print_stats(list<rider>& disembarked, elevator& elev);


private:
	int clock;
	int total_time;

};

void elevator_sim::run_simulation(int initclock) 
{
	clock = initclock;
	

}

void elevator_sim::print_stats(list<rider>& disembarked, elevator& elev)
{
	cout << "The elevator ran for " << total_time / 60 << " minutes." << endl;
	cout << "There were a total of " << elev.get_total_served() << " passengers." << endl;
	int averagewait;
	int averageride;
	list<rider>::iterator it = disembarked.begin();
	//for loop of disembarked to total average wait and average ride
}
