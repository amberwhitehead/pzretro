#include "graphics.h"

#include <algorithm>
#include "threads.h"

namespace graphics {

uint16_t framebuffer[framebuffer_len]{};
uint16_t framebuffer_screen[framebuffer_len]{};
pz::mutex mutex;
pz::mutex screen_mutex;

void clear()
{
    pz::lock_guard guard(mutex);
    std::fill(framebuffer, framebuffer + framebuffer_len, 0x0080);
}

void fill(int x, int y, int w, int h, uint16_t color)
{
    pz::lock_guard guard(mutex);
    if (x == 0 && y == 0 && w == width && h == height) {
        std::fill(framebuffer, framebuffer + framebuffer_len, color);
    } else {
        for (int i = 0; i < h; i++) {
            std::fill(framebuffer + x + y * stride + i * stride, framebuffer + x + y * stride + i * stride + w, color);
        }
    }
}

void flip()
{
    pz::lock_guard guard1(mutex);
    pz::lock_guard guard2(screen_mutex);
    std::copy(framebuffer, framebuffer + framebuffer_len, framebuffer_screen);
}

} // namespace graphics
