#include <zephyr/kernel.h>
#include <zephyr/random/rand32.h>
#include "RandomGenerator.h"

int ZephyrRandomGenerator::getRandomNumber(uint32_t* value) {
#if CONFIG_TEST_RANDOM_GENERATOR
    sys_rand_get(value, sizeof(uint32_t));  // Zephyr's random number generator function for test purpose
    return 0;
#else
    return sys_csrand_get(value, sizeof(uint32_t));  // Zephyr's random number generator function with nordic security backend
#endif
}