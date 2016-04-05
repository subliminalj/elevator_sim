
#include <cstdlib>
#include <ctime>

class Random {

public:

	Random() {
		std::srand(std::time(0));
	}

	Random(int seed) {
		std::srand(seed);
	}

	int next_int(int n) {
		return rand() % n;
	}

	double next_double(double m) {
		return (rand() % int(100*m))/100;
	}
};
