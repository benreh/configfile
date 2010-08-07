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
#include "configfile.h"
#include <fstream>

using namespace std;

void str2lower(string &str) {
	for(unsigned int i=0;i<str.size();i++)
	{
		str[i] = tolower(str[i]);
	}
}
std::string trim(std::string const& source, char const* delims = " \t\r\n") {
  std::string result(source);
  std::string::size_type index = result.find_last_not_of(delims);
  if(index != std::string::npos)
    result.erase(++index);

  index = result.find_first_not_of(delims);
  if(index != std::string::npos)
    result.erase(0, index);
  else
    result.erase();
  return result;
}


ConfigFile::ConfigFile(string myfilename) {
	filename=myfilename;
	fstream f;
	f.open(filename.c_str(),fstream::in);
	if (!f.is_open())	{
		cerr << "Configfile '" << myfilename << "' not found!" << endl;
		return;
	}
	string line;
	int lnr=-1;
	while (getline(f,line))	{
		lnr++;
		//Skip Comments and empty lines
		if (! line.length()) continue;
	    if (line[0] == '#') continue;
    	if (line[0] == ';') continue;

		int posTrenner=line.find('=');
		if (posTrenner==-1)
			posTrenner=line.find(' ');
		if (posTrenner==-1) {
			cerr << "WARNING: Statement '" << line << "' in file "<< filename << ":"<<lnr<<" is invalid and therefor will be ignored" << endl;
			continue;
		}
		string key=trim(line.substr(0,posTrenner));
		string value=trim(line.substr(posTrenner+1));

		//Case insensitive
		str2lower(key);

		if (datamap[key]!="") {
			cerr << "WARNING: Statement '" << line << "' in file "<< filename << ":"<<lnr<<" redefines a value!" << endl;
		}
		datamap[key]=value;
	 }
	f.close();	
}

void ConfigFile::dump(void) {
	for (map<string,string>::iterator iter= datamap.begin(); iter!=datamap.end();iter++){
		cout << "key: '" << iter->first <<"' \t value: '"<< iter->second <<"'"<<endl;
	}
}
ConfigFile::~ConfigFile() {
}

