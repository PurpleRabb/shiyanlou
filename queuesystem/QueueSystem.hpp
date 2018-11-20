#ifndef QUEUE_SYSTEM_H_
#define QUEUE_SYSTEM_H_

#include "Event.hpp"
#include "Queue.hpp"
#include "ServiceWindow.hpp"
#include "Node.hpp"

class QueueSystem {
public:
	QueueSystem(int total_service_time,int window_num);
	~QueueSystem();

	void simulate(int simulate_num);
	
	inline double getAvgStayTime() const {
		return avg_stay_time;
	}

	inline double getAvgCustomers() const {
		return avg_customers;
	}

private:
	double run();
	void init();
	void end();
	
	int getIdleServiceWindow();
	void customerArrived();
	void customerDeparture();
	int window_num;
	int total_service_time;
	int total_customer_stay_time;
	int total_customer_num;

	ServiceWindow * windows;
	Queue<Customer> customer_list;
	Queue<Event>	event_list;
	Event* current_event;
	
	double avg_customers;
	double avg_stay_time;
};
#endif
