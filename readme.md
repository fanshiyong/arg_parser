# Copyright

 The library file arg_parser.h is licensed under the [Apache 2 License](https://github.com/opencv/opencv/blob/master/LICENSE).

# Install

Just include arg_parser.h.

# Example

```c++
#include "arg_parser.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	arg_parser cmd("c:d"); //c is an option followed by a value, d is a switch.
	if(cmd.parse(argc, argv)){
		printf("args:\n");
		//cmd.args is a instance of type std::vector<std::string>.
		for(int i=0; i<cmd.args.size(); i++){
			printf("\t%s\n", cmd.args[i].c_str());
		}

		printf("opts:\n");
		//cmd.opts is a instance of type std::map<char, std::string>.
		if(cmd.opts.count('c'))
			printf("\tc\t%s\n", cmd.opts['c'].c_str());
		if(cmd.opts.count('d'))
			printf("\td\n");

	}else{
		printf("usage: example ip [file] [-c channel] [-d]\n");
	}
	return 0;
}


```

