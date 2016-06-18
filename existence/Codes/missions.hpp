#ifndef MISSIONS_H_INCLUDED_
#define MISSIONS_H_INCLUDED_
#include "object.hpp"
using namespace std;

class missions {
	public:
	virtual void status();
	bool over;
	
	interaction inter;
};

class levelOne : public missions {
	public:
	void status();
};

class levelTwo : public missions {
	public:
	void status();
};

class interaction2 {
	public:
	void ini(interaction);
	bool missShow;
	map<int, missions*> levels;
};

void interaction2::ini(interaction In_inter) {
	missShow = false;
	missions* lv1 = new levelOne();
	missions* lv2 = new levelTwo();
	lv1->inter = In_inter;
	lv2->inter = In_inter;
	
	levels[1] = lv1;
	levels[2] = lv2;
}

void levelOne::status() {
	if(inter.mO["laptop"]->owner == "hands" && inter.mO["phone"]->owner == "hands") over = true;
}

void levelTwo::status() {
	if(inter.mO["laptop"]->owner == "world") over = true;
}

void missions::status() {
	cout << "Missions main status..." << endl;
}

#endif
