#include "elevator.h"
#include "rider.h"
using namespace std;


void elevator::add_rider(rider& newrider)
{
	list<rider>::iterator it = rider_list.begin();

	for (it = rider_list.begin(); it != rider_list; it++) 
	{
		if (it->get_destination < newrider.get_destination)
			rider_list.insert(it,newrider)
	}
	

}

void elevator::rider_destination()
{
	//destination.pop_front();
}