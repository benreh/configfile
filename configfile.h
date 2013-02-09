/*	Copyright 2010 Benjamin Reh <ich@benjaminreh.de>
*
*	This file is part of 'configfile'.
*
*    'configfile' is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation version 3 of the License.
*
*    'configfile' is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with 'configfile'.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIGFILE_H
#define CONFIGFILE_H
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <iostream>


class ConfigFile {
public:
ConfigFile(std::string filename);
ConfigFile();
bool load(std::string filename);

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

template < typename T>
T getvalue(std::string key, T defaultValue) {
	std::string str = datamap[key];
	if (str=="") {
		return defaultValue;
	}
	return getvalue<T>(key);
}

private:

std::map<std::string,std::string> datamap;
std::string filename;
};

#endif
