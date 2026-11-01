/*
 * Fallback for libcs without malloc_usable_size(), used by QuickJS-ng's
 * memory accounting. Returning 0 matches QuickJS's own fallback.
 */
#include <stddef.h>

size_t malloc_usable_size(void *ptr)
{
    (void)ptr;
    return 0;
}
