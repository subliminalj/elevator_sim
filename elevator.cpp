#include "floors.h"
#include "elevator.h"
#include "elevator_sim.h"
#include "rider.h"

void main(void)
{
	elevator_sim simulation(500);
	simulation.run_simulation;
	simulation.print_stats;
}