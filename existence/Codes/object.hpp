#ifndef OBJECT_H_INCLUDED_
#define OBJECT_H_INCLUDED_
#include "../Other Files/set.hpp"
//#include "../Codes/player.hpp"
using namespace std;

class object {
public:
	virtual void use();
	bool surface, usable;
	string owner;

	void ini(string);
};

class laptop : public object{
public:
	void use();
	laptop() { usable = true; }
};

class phone : public object {
public:
	void use();
	phone() { usable = true; }
};

class interaction {
public:
	map<string, object*> mO;
	vector<string> values;
	void ini(bool);
};

#endif
