#include <iostream>
#include <cstdlib>
#include "QueueSystem.hpp"

using namespace std;
int main() {
	std:srand((unsigned)time(0));
	int total_service_time = 240; //4 hours
	int window_num = 4;
	int simulate_num = 10000000;

	QueueSystem system(total_service_time,window_num);
	system.simulate(simulate_num);
	cout << "The average time of customer stay in bank: " << \
		system.getAvgStayTime() << endl;

	cout << "The number of customer arrive bank per min:" << \
		system.getAvgCustomers() << endl;
	return 0;	
}
