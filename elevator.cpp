#include "elevator.h"
#include "rider.h"
#include "elevator_sim.h"

void main(void)
{
	elevator shaft1;
	elevator_sim simulation;
	list<rider> rider_list;
	list<rider> waiting_list;
	list<rider> disembarked;
	simulation.run_simulation(0, shaft1);
	simulation.print_stats(disembarked, shaft1);
	
}