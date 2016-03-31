#ifndef _FLOORS_H_
#define _FLOORS_H_

#include "elevator.h"

class floors
{
private:
	int maxfloornumber;
	bool goingup;
	bool goingdown;
public:
	get_maxfloornum() { return maxfloornumber; }
	get_up_bool() { return goingup; }
	get_down_bool() { return goingdown; }
};


floors::floors(): maxfloornumber(0), goingup(false), goingdown(false);
floors::floors(int, bool,bool): maxfloornumber(0), goingup(false), goingdown(false);
#endif
