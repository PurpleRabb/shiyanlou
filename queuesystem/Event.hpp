#ifndef EVENT_H_
#define EVENT_H_
#include "Random.hpp"
#include "Node.hpp"
#include <cstdlib>

struct Event {
	int occur_time;
	int event_type; //-1 arrive,0 leave
	Event *next;

	Event(int occur_time = Random::uniform(RANDOM_PARAMETER),
		int event_type = -1):
		occur_time(occur_time),
		event_type(event_type),
		next(NULL) {}
};

//typedef struct Event Event;

#endif
