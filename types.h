#pragma once

#include "common.h"

enum token {
	// Reserved words
	AUTO,
	BREAK,
	CASE,
	CHAR,
	CONST,
	CONTINUE,
	DEFAULT,
	DO,
	DOUBLE,
	ELSE,
	ENUM,
	EXTERN,
	FLOAT,
	FOR,
	GOTO,
	IF,
	INT,
	LONG,
	REGISTER,
	RETURN,
	SHORT,
	SIGNED,
	SIZEOF,
	STATIC,
	STRUCT,
	SWITCH,
	TYPEDEF,
	UNION,
	UNSIGNED,
	VOID,
	VOLATILE,
	WHILE,
	// Operators
	DOT, // .
	TILDE, // ~
	EXCLAMATION, // !
	PERCENT, // %
	PERCENT_EQUAL, // %=
	CARET, // ^
	CARET_EQUAL, // ^=
	AMPERSAND, // & 
	AMP_AMP, // &&
	AMP_EQUAL, // &=
	PIPE, // |
	PIPEPIPE, // ||
	PIPE_EQUAL, // |=
	ASTERISK, // * 
	ASTERISK_EQUAL, // *=
	LPAREN, // (
	RPAREN, // ) 
	LBRACK, // [
	RBRACK, // ]
	LBRACE, // {
	RBRACE, // }
	MINUS, // - 
	MINUS_MINUS, // --
	MINUS_EQUAL, // -=
	PLUS, // +
	PLUS_PLUS, // ++
	PLUS_EQUAL, // +=
	EQUALS, // =
	EQUAL_EQUAL, // ==
	NEQUAL, // !=
	COLON, // :
	SEMICOLON, // ;
	SINGLE_QUOTE, // '
	DOUBLE_QUOTE, // "
	COMMA, // ,
	LESS_THAN, // < 
	LESS_LESS, // <<
	LESS_EQUAL, // <=
	LESS_LESS_EQUAL, // <<=
	GREATER_THAN, // >
	GREAT_GREAT, // >>
	GREATER_EQUAL, // >=
	GREAT_GREAT_EQUAL, // >>=
	ARROW, // ->
	SLASH, // /
	SLASH_SLASH, // //
	SLASH_EQUAL, // /=
	QUESTION_MARK, // ?
	// Non-reserved words
	IDENT, // Any string, beginning with an _ or a letter, that isn't reserved
	NUMERAL, // Any string beginning with a numeral
};

struct set_entry {
	char *str;
};

/*
 * strset is a hash based set.
 * strset cannot be removed from. Strings can only be added.
 * When doing a lookup, an index or -1 is returned. The index can be used to
 * index into a table to implement a map. -1 indicates the value searched for
 * is not in the set.
 */
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
