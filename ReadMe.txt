#include "arg_parser.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	arg_parser args("c:d");
	int  opt_c = 0;
	bool opt_d = false;

	if(args.parse(argc, argv)){
		printf("arguments:\n");
		for(int i=0; i<args.arguments.size(); i++){
			printf("\t%s\n", args.arguments[i].c_str());
		}

		printf("options:\n");
		for(arg_parser::opt_iter it = args.options.begin(); it!=args.options.end(); it++){
			printf("\t%c\t%s\n", it->first, it->second.c_str());
		}

		if(args.options.count('c'))
			opt_c = atoi(args.options['c'].c_str());
		if(args.options.count('d'))
			opt_d = true;

	}else{
		std::string::size_type pos;
		std::string argv0(argv[0]);
		pos = argv0.rfind('\\');
		if(pos != std::string::npos){
			argv0 = argv0.substr(pos+1);
		}
		printf("usage: %s ip [file] [-c channel] [-d]\n", argv0.c_str());
	}
	return 0;
}

