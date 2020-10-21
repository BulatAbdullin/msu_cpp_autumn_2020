#ifndef PARSER_HPP
#define PARSER_HPP


class TokenParser
{
private:
	int len;
	char *text;
	void (*start_callback)();
	void (*end_callback)();
	void (*integer_token_callback)(const char *integer);
	void (*string_token_callback)(const char *string);

	enum states {
		space, integer, string
	};
	states getInitialState() const;
	void tokenCallback(
			const char *token, char *current, states state) const;
public:
	TokenParser(const char *text);
	~TokenParser();
	void setText(const char *text);
	void parse() const;

	inline const char *getText() const
	{
		return text;
	}

	inline void setStartCallback(void (*start_callback)())
	{
		this->start_callback = start_callback;
	}

	inline void setEndCallback(void (*end_callback)())
	{
		this->end_callback = end_callback;
	}

	inline void setIntegerTokenCallback(
			void (*integer_token_callback)(const char *integer))
	{
		this->integer_token_callback = integer_token_callback;
	}

	inline void setStringTokenCallback(
			void (*string_token_callback)(const char *string))
	{
		this->string_token_callback = string_token_callback;
	}
};

#endif
