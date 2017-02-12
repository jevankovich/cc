#include "hash.h"

#define FNV_PRIME 0x100000001b3
#define FNV_OFFSET 0xCBF29CE484222325

uint64_t strhash(const char *str) {
	uint64_t hash = FNV_OFFSET;
	for (; *str; str++) {
		hash ^= *str;
		hash *= FNV_PRIME;
	}
	
	return hash;
}

uint64_t memhash(const char *buf, size_t len) {
	uint64_t hash = FNV_OFFSET;
	for (size_t i = 0; i < len; i++) {
		hash ^= *buf;
		hash *= FNV_PRIME;
	}

	return hash;
}
