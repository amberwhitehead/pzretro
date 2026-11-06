#include "pztime.h"

#include "threads.h"

namespace pztime {

uint64_t cumulative{0};
pz::mutex mutex;

uint64_t elapsed()
{
    pz::lock_guard guard(mutex);
    return cumulative;
}

void increment(uint64_t delta)
{
    pz::lock_guard guard(mutex);
    cumulative += delta;
}

} // namespace pztime
