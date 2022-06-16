// ArgParser.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "arg_parser.h"

int _tmain(int argc, char* argv[])
{
	arg_parser args("c:d");
	int c=0;
	bool d=false;
	if(args.parse(argc, argv)){
		for(arg_parser::iterator it = args.begin(); it!=args.end(); it++){
			printf("%c\t%s\n", it->first, it->second.c_str());
		}

		if(args.count('c'))
			c = atoi(args['c'].c_str());
		if(args.count('d'))
			d = true;
	}else{
		std::string::size_type pos;
		std::string argv0(argv[0]);
		pos = argv0.rfind('\\');
		if(pos != std::string::npos){
			argv0 = argv0.substr(pos+1);
		}
		printf("usage: %s [-c channel] [-d]\n", argv0.c_str());
	}
	return 0;
}

