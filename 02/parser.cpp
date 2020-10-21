#include <string.h>
#include <ctype.h>

#include "parser.hpp"

static void default_callback()
{}

static void default_token_callback(const char *token)
{}

TokenParser::TokenParser(const char *text)
		: len(strlen(text))
		, text(new char[len + 1])
		, start_callback(&default_callback)
		, end_callback(&default_callback)
		, integer_token_callback(&default_token_callback)
		, string_token_callback(&default_token_callback)
{
	strcpy(this->text, text);
}

TokenParser::~TokenParser()
{
	delete[] text;
}

void TokenParser::setText(const char *text)
{
	delete[] this->text;
	len = strlen(text);
	this->text = new char[len + 1];
	strcpy(this->text, text);
}

TokenParser::states TokenParser::getInitialState() const
{
	if (isspace(*text)) {
		return space;
	} else if (isdigit(*text)) {
		return integer;
	}
	return string;
}

void TokenParser::tokenCallback(
		const char *token, char *current, states state) const
{
	/* In order to pass a correct string to either of the token callback
	 * functions we place '\0' right after the token and then restore the old
	 * value: either a whitespace character or, if we are at the end
	 * of the text, '\0'.
	 */
	char save_current = *current;
	*current = '\0';
	if (state == integer) {
		this->integer_token_callback(token);
	} else {
		this->string_token_callback(token);
	}
	*current = save_current;
}

void TokenParser::parse() const
{
	this->start_callback();
	states state = this->getInitialState();
	const char *token = text;
	// loop throught text up until the terminating '\0' character
	for (char *current = this->text + 1; *(current - 1); current++) {
		// Finite-state machine with 3 states
		switch (state) {
		case space:
			if (isdigit(*current)) {
				state = integer;
			} else if(*current && !isspace(*current)) {
				state = string;
			}
			token = current;
			break;
		case integer:
			if (isspace(*current) || *current == '\0') {
				tokenCallback(token, current, state);
				state = space;
			} else if (!isdigit(*current)) {
				state = string;
			}
			break;
		case string:
			if (isspace(*current) || *current == '\0') {
				tokenCallback(token, current, state);
				state = space;
			}
			break;
		}
	}
	this->end_callback();
}
