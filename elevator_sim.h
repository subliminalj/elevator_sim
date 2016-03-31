#include "elevator.h"
#include "rider.h"
#include <iostream>
class elevator_sim
{
public:
	elevator_sim(int timetorun);
	~elevator_sim();
	void run_simulation();
	void print_stats();


private:
	int clock;
	int total_time;
	int timetorun;

};

void elevator_sim::run_simulation() {}

elevator_sim::elevator_sim(int timetorun)
{
	for (clock = 0; clock < timetorun; clock++)
	{
		elevator shaft1(50, 5);
		shaft1.update();
		total_time++;
	}
}

elevator_sim::~elevator_sim()
{
}

void elevator_sim::print_stats()
{
	cout << "The elevator ran for " << total_time / 60 << " minutes." << endl;
	cout << "There were a total of " << shaft1.get_total_served() << " passengers." << endl;
}
