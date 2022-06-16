#include "arg_parser.h"

arg_parser::arg_parser(const char * format) {
	while(*format != '\0') {
		if(*(format+1) == ':'){
			opt_types[*format] = true;
			format += 2;
		}else{
			opt_types[*format] = false;
			format += 1;
		}
	}
}

bool arg_parser::parse(int argc, char * argv[]) {

	char arg_name;
	int state = 0; //0 option or argument, 1 option value.
	std::map<char, bool>::iterator it;

	arguments.clear();
	options.clear();

	for(int i=1; i<argc; i++) {
		if(state == 0){
			if(argv[i][0] == '-'){
				if(argv[i][1] != '\0' && argv[i][2] == '\0'){
					it = opt_types.find(argv[i][1]);
					if(it != opt_types.end()){
						if(it->second == true){
							arg_name = argv[i][1];
							state = 1;
						}else{
							options[argv[i][1]] = std::string();
							state = 0;
						}
					}else{
						return false; //invalid argument name.
					}
				}else{
					return false; //invalid argument name.
				}
			}else{
				arguments.push_back(std::string(argv[i]));
				state = 0;
			}
		}else{
			if(argv[i][0] == '-'){ //value was expected, but not found.
				return false;
			}else{
				options[arg_name] = std::string(argv[i]);
				state = 0;
			}
		}
	}

	if(state == 1) //value was expected, but not found.
		return false;
	return true;
}
