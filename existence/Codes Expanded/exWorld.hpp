#ifndef exWorld_H_INCLUDED_
#define exWorld_H_INCLUDED_
#include "../Codes/world.hpp"
using namespace std;

void world::status(interaction inter) {
	bool prFlag = false;

	cout << endl;
	for(map<string, object*>::iterator it=inter.mO.begin();it!=inter.mO.end();it++) {
		if(it->second->owner == "world") {
			prFlag = true;
			cout << it->first << endl;
		}
	}

	if(!prFlag) cout << endl << "Seems you're holding everything hahaha!" << endl << endl;
	else cout << endl;
}

#endif