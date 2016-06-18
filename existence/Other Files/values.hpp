#ifndef VALUES_H_INCLUDED
#define VALUES_H_INCLUDED
#include "set.hpp"
using namespace std;

class values {
	map<string, int> comValue;
public:
	int ini(string);
	values();
} val;

int values::ini(string in) {
	return comValue[in];
}

values::values() {
	comValue.insert(make_pair("take", 1));
	comValue.insert(make_pair("reset", 2));
	comValue.insert(make_pair("show", 3));
	comValue.insert(make_pair("use", 4));
	comValue.insert(make_pair("exit", 5));
	comValue.insert(make_pair("keep", 6));
	comValue.insert(make_pair("save", 7));
	comValue.insert(make_pair("load", 8));
}

#endif