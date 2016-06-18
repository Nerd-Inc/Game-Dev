#include "Codes Expanded/exCommand.hpp"
using namespace std;

int main() {
	command com;
	execute exi;
	player ply;
	world wld;
	object obj1;
	interaction inter;
	interaction2 inter2;

	loadFile(inter, ply);
	cout << "showing player at: " << &ply.mission << endl << endl;
	inter2.ini(inter);

	while(!fExit) {
		com.input();
		com.ini();

		exi.input(com, ply, wld, inter, inter2);
		cout << "Initializing execution!" << endl;
		exi.ini();

		cout << endl;
	//ply.status(obj1);
	//wld.status(obj1);
	}

	return 0;

}
