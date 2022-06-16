#ifndef __ARGS_PARSER_H
#define __ARGS_PARSER_H

#include <map>
#include <string>

class arg_parser : public std::map<char, std::string> {
public:
	arg_parser(const char * format);
	bool parse(int argc, char * argv[]);

private:
	std::map<char, bool> arg_types;
};

#endif //define __ARGS_PARSER_H