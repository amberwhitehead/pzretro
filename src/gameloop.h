#pragma once

#include <atomic>
#include <memory>

#include "js.h"
#include "threads.h"

class GameLoop
{
    // Config
    std::string game_contents;
    bool use_puzzlescript_plus;
    bool use_custom_font;
    bool truncate_backups;

    // JavaScript context
    std::unique_ptr<js::Context> js_context;

#ifndef PZ_NO_THREADS
    // JavaScript thread
    std::thread js_thread;
    std::atomic<bool> js_thread_active;
#endif
    std::atomic<bool> waiting_serialize;
    std::atomic<bool> waiting_deserialize;

    // Stored serialized state
    std::string serialized;

    void init();
    void handle_requests();
    void tick();
#ifndef PZ_NO_THREADS
    void thread_func();
#endif
public:
    GameLoop(std::string game_contents, bool use_puzzlescript_plus, bool use_custom_font);
    ~GameLoop();
    // Run one frame of the game loop when not using a thread
    void step();
    void set_truncate();
    std::string serialize();
    void deserialize(std::string data);
};
