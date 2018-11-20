#ifndef Random_hpp
#define Random_hpp
class Random {
public:
	static double uniform(double max = 1) {
		return ((double)std::rand()/(RAND_MAX))*max;//[0,max)
	}
};
#endif
