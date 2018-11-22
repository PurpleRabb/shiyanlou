#include "QueueSystem.hpp"

QueueSystem::QueueSystem(int total_service_time, int window_num): \
		total_service_time(total_service_time),window_num(window_num),
		total_customer_stay_time(0),total_customer_num(0) {
	this->windows = new ServiceWindow[window_num];
}

QueueSystem::~QueueSystem() {
	delete[] windows;
}

void QueueSystem::simulate(int simulate_num) {
	double sum = 0;
	for(int i=0;i!=simulate_num;++i)
	{
		sum += run();
	}
	avg_stay_time = (double)sum/simulate_num;
	avg_customers = (double)total_customer_num/(total_service_time*simulate_num);
}

void QueueSystem::init() {
	Event *event = new Event;
	current_event = event;
}

double QueueSystem::run() {
	this->init();
	while(current_event) {
		if(current_event->event_type == -1) {
			customerArrived();
		} else {
			customerDeparture();
		}
		delete current_event;
		current_event = event_list.dequeue();
	}

	this->end();
	return (double)total_customer_stay_time/total_customer_num;
}

void QueueSystem::end() {
	for(int i=0;i!=window_num;++i) {
		windows[i].setIdle();
	}
	customer_list.clearQueue();
	event_list.clearQueue();
}

void QueueSystem::customerArrived() {
	total_customer_num++;

	//assume it will be a customer in 100mins.
	int enter_time = Random::uniform(100);
	int time = current_event->occur_time + enter_time;
	Event temp_event(time);
	if(time < total_service_time) {
		event_list.orderEnqueue(temp_event);
	}

	Customer *customer = new Customer(current_event->occur_time);
	if(!customer) {
		exit(-1);
	}
	customer_list.enqueue(*customer);
	int idleIndex = getIdleServiceWindow();
	if(idleIndex >= 0) {
		customer = customer_list.dequeue();
		windows[idleIndex].serveCustomer(*customer);
		windows[idleIndex].setBusy();
		Event temp_event(current_event->occur_time + customer->duration,\
			idleIndex);
		event_list.orderEnqueue(temp_event);
	}
	delete customer;
}

int QueueSystem::getIdleServiceWindow()
{
	for(int i =0; i!=window_num;++i) {
		if(windows[i].isIdle()) {
			return i;
		}
	}
	return -1;
}

void QueueSystem::customerDeparture() {
	if(current_event->occur_time < total_service_time) {
		total_customer_stay_time += current_event->occur_time - \
			windows[current_event->event_type].getCustomerArriveTime();
		if(customer_list.length()) {
			Customer *customer;
			customer = customer_list.dequeue();
			windows[current_event->event_type].serveCustomer(*customer);
			
			Event temp_event(current_event->occur_time + customer->duration,\
				current_event->event_type);
			event_list.orderEnqueue(temp_event);
			delete customer;
		} else {
			windows[current_event->event_type].setIdle();
		}
	}
}
