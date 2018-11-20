#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstdlib>

#include "Event.hpp"

template <typename T>

class Queue {
public:
	Queue();
	~Queue();

	void clearQueue();
	T* enqueue(T &node);
	T* dequeue();
	T* orderEnqueue(Event &event);

	int length();

private:
	T* front;
	T* rear;
};
#endif
