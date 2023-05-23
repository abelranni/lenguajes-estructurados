#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define DEBUG_LEVEL 2

#if DEBUG_LEVEL >= 1
#define DEBUG1(...) printf(__VA_ARGS__)
#else
#define DEBUG1(...)
#endif

#if DEBUG_LEVEL >= 2
#define DEBUG2(...) printf(__VA_ARGS__)
#else
#define DEBUG2(...)
#endif

#if DEBUG_LEVEL >= 3
#define DEBUG3(...) printf(__VA_ARGS__)
#else
#define DEBUG3(...)
#endif

#endif // DEBUG_H
