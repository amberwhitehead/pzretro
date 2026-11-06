#include "event.h"

#include "threads.h"
#include <queue>

namespace event {

std::queue<Event> events;
pz::mutex mutex;

void push(Event e)
{
    pz::lock_guard guard(mutex);
    events.push(e);
}

Event pop()
{
    pz::lock_guard guard(mutex);
    Event result{false, 0};
    if (events.size() > 0) {
        result = events.front();
        events.pop();
    }
    return result;
}

}