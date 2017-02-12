#pragma once

#include "common.h"
#include "types.h"

struct strset *strset_init(void);
void strset_destroy(struct strset *);

int strset_insert(struct strset *, const char *);
int strset_get(const struct strset *, const char *);
