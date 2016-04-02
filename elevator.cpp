#include "elevator.h"
#include "rider.h"
#include "elevator_sim.h"
using namespace std;



void main(void)
{
	elevator_sim() simulation;
	simulation.run_simulation();
	simulation.print_stats();
}