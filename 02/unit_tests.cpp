#ifndef UNIT_TETSTS_CPP_HEADER
#define UNIT_TETSTS_CPP_HEADER

#include <string.h>

#include "parser.hpp"

static bool started = false, ended = false;

void hello() {
	started = true;
}

void bye() {
	ended = true;
}

void trivial()
{
	TokenParser parser("123 -123 hello");
	parser.setText("   aa 12a1 -1 23 2222    g  ");
	parser.setStartCallback(hello);
	parser.setEndCallback(bye);
	parser.parse();
}

static const char *integer_tokens[] = { "123", "54", "2222", "22", "483" };
static const char **current_integer_token = integer_tokens;
static const char *string_tokens[] = { "-123", "hello", "g", "world", "g" };
static const char **current_string_token = string_tokens;

void integer_token(const char *token)
{
	assert(strcmp(token, *current_integer_token) == 0);
	current_integer_token++;
}

void string_token(const char *token)
{
	assert(strcmp(token, *current_string_token) == 0);
	current_string_token++;
}

void test()
{
	TokenParser parser("");
	parser.setIntegerTokenCallback(integer_token);
	parser.setStringTokenCallback(string_token);
	const char *text = "   123 -123 \n 54 hello 2222 g \t 22 483 \tworld   g";
	parser.setText(text);
	parser.parse();
}

#endif
