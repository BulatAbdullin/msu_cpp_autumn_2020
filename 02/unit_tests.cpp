#ifndef UNIT_TETSTS_CPP_HEADER
#define UNIT_TETSTS_CPP_HEADER

#include "parser.hpp"

void hello() {
	puts("Hello, world!");
}

void bye() {
	puts("Good bye, world!");
}

void trivial()
{
	TokenParser parser("123 -123 hello");
	parser.setText("   aa 12a1 -1 23 2222    g  ");
	parser.setStartCallback(hello);
	parser.setEndCallback(bye);
	parser.parse();
	puts("");
}

void integer_token(const char *token)
{
	printf("Integer: %s\n", token);
}

void string_token(const char *token)
{
	printf("String: %s\n", token);
}

void token_print()
{
	const char *text = "123 -123 hello";
	TokenParser parser(text);
	parser.setIntegerTokenCallback(integer_token);
	parser.setStringTokenCallback(string_token);
	puts(text);
	parser.parse();
	puts("");
	text = "   aa 12a1 -1 23 2222    g  ";
	puts(text);
	parser.setText(text);
	parser.parse();
	puts("");
}

#endif
