#pragma once

/*
 * Threading primitives. Define PZ_NO_THREADS on platforms without
 * std::thread/pz::mutex to run the JavaScript game loop on the main thread.
 */
#ifdef PZ_NO_THREADS

namespace pz
{
struct mutex
{
    void lock() {}
    void unlock() {}
};

struct lock_guard
{
    explicit lock_guard(mutex &) {}
};
}

#else

#include <mutex>
#include <thread>

namespace pz
{
using mutex = std::mutex;
using lock_guard = std::lock_guard<std::mutex>;
}

#endif
