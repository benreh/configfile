#ifndef CONFIGFILE_H
#define CONFIGFILE_H
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <iostream>


class ConfigFile {
public:
ConfigFile(std::string myfilename);
~ConfigFile();
void dump(void);


template < typename T>
T getvalue(std::string key) {
	std::string str = datamap[key];
	if (str=="") {
		std::cerr << "WARNING: '" << key <<"' was not defined in " << filename << "! Value is undefined!" << std::endl;
	}
	std::stringstream ss;
	ss << str;
	T value;
	ss >> value;
	return value;	
}
private:

std::map<std::string,std::string> datamap;
std::string filename;
};

#endif
