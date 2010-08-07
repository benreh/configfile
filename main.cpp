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
	return 0;
}
