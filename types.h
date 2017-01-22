#pragma once

#include "common.h"

enum token {
	IDENT, // Any string beginning with an _ or a letter
	NUMERAL, // Any string beginning with a numeral
	// The following tokens are single characters
	TILDE, // ~
	EXCLAMATION, // !
	PERCENT, // %
	CARET, // ^
	AMPERSAND, // & 
	ASTERISK, // * 
	LPAREN, // (
	RPAREN, // ) 
	MINUS, // - 
	PLUS, // +
	EQUALS, // =
	COLON, // :
	SEMICOLON, // ;
	SINGLE_QUOTE, // '
	DOUBLE_QUOTE, // "
	COMMA, // ,
	LESS_THAN, // < 
	GREATER_THAN, // >
	SLASH, // /
	QUESTION_MARK, // ?
};

struct set_entry {
	uint64_t hash;
	char *str;
};

struct strset {
	// TODO: Implement this
	// Should have a private heap for strings
	// since hash collisions are (should be) rare, 
	
	// When size/capacity exceeds some threshold, we need to expand.
	// Expanding sounds like a pain

	size_t size; // The number of entries in the heap
	size_t capacity; // The total number of possible entries in the heap
	struct set_entry *entries; // An array of the entries in the set
	size_t heap_capacity; // The current capacity of the heap
	char *heap; // A pointer to the beginning of the heap
	char *next_heap; // The next location in the heap available for a string
};

struct lex_state {
	char curr[64];
	size_t ntok;
	enum token *toks;
	struct strset idents;
};
