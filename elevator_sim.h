#include "elevator.h"
class elevator_sim
{
public:
	elevator_sim();
	~elevator_sim();
	void run_simulation();
	void print_stats();


private:
	int clock;
	int total_time;


};

void elevator_sim::run_simulation() {}
void elevator_sim::print_stats() {}

elevator_sim::elevator_sim()
{
}

elevator_sim::~elevator_sim()
{
}