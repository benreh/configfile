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
#include <iostream>
#include "configfile.h"
using namespace std;

int main () {
	ConfigFile cfg("test.cfg");
	cout << "Dump:" << endl;
	cfg.dump();
	cout << endl;
	cout << cfg.getvalue<string>("who") << endl;
	cout << cfg.getvalue<float>("number") << endl;
	cout << cfg.getvalue<int>("number") << endl;
	cout << cfg.getvalue<int>("notThere") << endl;
	cout << cfg.getvalue<int>("notThere",5) << endl;
	return 0;
}
