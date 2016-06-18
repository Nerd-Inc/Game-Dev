#ifndef exPlayer_H_INCLUDED_
#define exPlayer_H_INCLUDED_
#include "../Codes/player.hpp"
using namespace std;

void player::status(interaction inter) {
	bool prFlag = false;

	cout << endl;
	for(map<string, object*>::iterator it=inter.mO.begin();it!=inter.mO.end();it++) {
		if(it->second->owner == "hands") {
			prFlag = true;
			cout << it->first << endl;
		}
	}

	if(!prFlag) cout << endl << "You don't have any object in your hand!" << endl << endl;
	else cout << endl;
}

#endif