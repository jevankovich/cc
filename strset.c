#include "strset.h"

#include <string.h>

#include "hash.h"

struct strset *strset_init(void) {
	struct strset *set = malloc(sizeof(struct strset));
	if (!set) {
		perror_here();
		return NULL;
	}

	set->size = 0;
	set->capacity = 128;
	set->entries = calloc(set->capacity, sizeof(*(set->entries)));
	if (!(set->entries)) {
		perror_here();
		goto fail_entries;
	}
	set->heap_capacity = 1024;
	set->heap = malloc(set->heap_capacity);
	if (!(set->heap)) {
		perror_here();
		goto fail_heap;
	}
	set->next_heap = set->heap;
	return set;

fail_heap:
	free(set->entries);
fail_entries:
	free(set);
	return NULL;
}

void strset_destroy(struct strset *set) {
	free(set->entries);
	free(set->heap);
	free(set);
}

/*
 * This expands the given set.
 * It will return a non-zero value when it encounters an error. 
 * In the case of an error, the set will be destroyed.
 * In the case of success, the set will have room for more entries.
 */
int strset_expand(struct strset *set) {
	// TODO: Implement
}

/*
 * This expands the heap portion of the given set. 
 * It will return a non-zero value when it encounters an error.
 * In the case of an error, the set will be destroyed.
 * In the case of succes, the heap in the given set will be expanded.
 */
int heap_expand(struct strset *set) {

}

/*
 * Inserts a string into the set.
 * If the string cannot be inserted (only possible in the case of a failed
 * resize) returns a non-zero value.
 * Otherwise returns zero.
 * If the string is already in the set, nothing happens
 */
int strset_insert(struct strset *set, const char *str) {
	size_t len = strlen(str);

	if (strset_get(set, str) >= 0) {
		return 0;
	}

	// if size / capacity > 80% we want to expand (probably)
	// multiply capacity by 4 and size by 5 and compare
	// size * 5 > capacity * 4 => expand
	if (set->size * 5 > set->capacity * 4) {
		strset_expand(set);
	}
	
	if (len + set->next_heap + 1 > set->heap_capacity + set->heap) {
		heap_expand(set);
	}

	// The string can now fit in the heap and there's room for an entry
	//set->entries[set->size++].str = set->next_heap;
	
	strcpy(set->next_heap, str);
	set->next_heap += len + 1;

	return 0;
}

/*
 * Performs a lookup in the set.
 * If the given str is in the set, returns its index.
 * Otherwise, returns -1
 */
int strset_get(const struct strset *set, const char *str) {
	
}
