#ifndef exObject_H_INCLUDED_
#define exObject_H_INCLUDED_
#include "../Codes/object.hpp"
using namespace std;

void interaction::ini(bool _def) {
	object *lap = new laptop();
	object *phn = new phone();

	mO["laptop"] = lap;
	mO["phone"] = phn ;

	if(_def) {
		lap->ini("world");
		phn->ini("world");
		//ply.mission = 1;
	} else {
		//for(unsigned int i=0;i<values.size() - 1;i+=2) mO[values[i]]->owner = values[i+1];
		mO[values[0]]->owner = values[1]; //laptop
		mO[values[2]]->owner = values[3]; //phone
	}
	
	//cout << "initializing..." << endl;
}

void object::ini(string own) { owner = own; }

void laptop::use() {
	cout << "using laptop..." << endl;
}

void phone::use() {
	cout << "using phone..." << endl;
}

void object::use() {
	cout << "using an object..." << endl;
}

#endif
