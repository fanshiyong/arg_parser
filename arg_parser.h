#ifndef __ARGS_PARSER_H
#define __ARGS_PARSER_H

#include <map>
#include <vector>
#include <string>

class arg_parser {
public:
	arg_parser(const char * format);
	bool parse(int argc, char * argv[]);

	std::vector<std::string> arguments;
	std::map<char, std::string> options;

	typedef std::map<char, std::string>::iterator opt_iter;
	typedef std::vector<std::string>::iterator arg_iter;

private:
	std::map<char, bool> opt_types;
};

#endif //define __ARGS_PARSER_H