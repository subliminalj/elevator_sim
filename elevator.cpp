//#include "elevator.h"
//#include "rider.h"
#include "elevator_sim.h"

void main(void)
{
	list<rider> rider_list;
	list<rider> waiting_list;
	list<rider> disembarked;
	elevator shaft1(20,.1, rider_list, waiting_list, disembarked);
	elevator_sim simulation;
	simulation.run_simulation(0, shaft1);
	simulation.print_stats(disembarked, shaft1);
	system("PAUSE");

}