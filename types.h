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

struct strset {
	// TODO: Implement this
	// Should have a private heap for strings
	// Since hash collisions are (should be) rare, 
};

struct lex_state {
	char curr[64];
	size_t ntok;
	enum token *toks;
	struct strset idents;
};
