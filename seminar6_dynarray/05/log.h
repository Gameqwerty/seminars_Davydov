#pragma once
#include <stdio.h>

#ifdef DEBUG
  #define LOG(msg) \
    do { fprintf(stderr, "[DEBUG] %s: %d: %s\n", __FILE__, __LINE__, (msg)); } while (0)
#else
  #define LOG(msg) ((void)0)
#endif
