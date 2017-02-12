#pragma once 

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define dprint(...) printf("(%s:%d)", __FILE__, __LINE__); printf(__VA_ARGS__)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define perror_here() fprintf(stderr, "(%s:%d)", __FILE__, __LINE__); perror(NULL)
