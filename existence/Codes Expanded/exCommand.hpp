#ifndef exCommand_H_INCLUDED_
#define exCommand_H_INCLUDED_
#include "../Codes/command.hpp"
#include <unistd.h>
using namespace std;

bool fExit = false;

command::command() {
	system("clear");
}

void command::input() {
	cout << "input: ";
	getline(cin, com_input);
}

void command::ini() {
	split_comInput = seperate(com_input);
}

void execute::input(command comInput, player& plyInput, world wldInput, interaction& interInput, interaction2& inter2Input) {
	//cout << "Executing.." << endl;
	com1 = comInput;
	ply = &plyInput;
	//cout << "Passed memory of player to: " << ply << endl;
	wld = wldInput;
	inter = &interInput;
	inter2 = &inter2Input;
	//cout << "Done.." << endl;
}

void execute::ini() {
	bool flagger = false;
	
	cout << "Switching input!" << endl;
	switch(val.ini(com1.split_comInput[0])) {
		case 1:  //take
		for(map<string, object*>::iterator it=inter->mO.begin();it!=inter->mO.end();it++) {
			if(it->first == com1.split_comInput[1]) {
				flagger = true; 
				if(it->second->owner != "hands") {
					inter->mO[com1.split_comInput[1]]->owner = "hands";
					cout << endl << com1.split_comInput[1] << " taken..." << endl << endl;
				} else cout << endl << "You already have " << com1.split_comInput[1] << endl << endl;
			}
		}
		if(!flagger) cout << endl << "Object isn't present in world!" << endl << endl; 
		break;

		case 2: //clear
		system("clear");
		return;

		case 3: //show
		if(com1.split_comInput[1] == "hands") ply->status(*inter);
		else if(com1.split_comInput[1] == "world") wld.status(*inter);
		return;

		case 4: //use
		for(map<string, object*>::iterator it=inter->mO.begin();it!=inter->mO.end();it++) {
			if(it->first == com1.split_comInput[1]) {
				flagger = true;
				if(it->second->usable) {
					cout << endl << "Yep! You can use that!" << endl << endl;
					break;
				}
			}
		}
		if(!flagger) cout << endl << "Object isn't present in world!" << endl << endl;
		break;

		case 5: //exit
		cout << endl << "Bye Bye..." << endl << endl;
		fExit = true;
		return;

		case 6: //keep
		for(map<string, object*>::iterator it=inter->mO.begin();it!=inter->mO.end();it++) {
			if(it->first == com1.split_comInput[1]) {
				flagger = true;
				if(it->second->owner == "hands") {
					it->second->owner = "world";
					cout << endl << com1.split_comInput[1] << " kept!" << endl << endl;
					break;
				} else {
					cout << endl << "You don't have the " << com1.split_comInput[1] << endl << endl;
					break;
				}
			}
		}
		if(!flagger) cout << endl << "Object isn't present in world!" << endl;
		break;

		case 7: //save
		//cout << endl << "Saving game modules.." << endl << endl;
		com1.saveFile(*inter, *ply, wld);
		break;

		case 8: //load
		loadFile(*inter, *ply);
		inter2->missShow = false;
		return;
		
		default:
		cout << endl << "Error with input size..." << endl << endl;
		return;
	}
	
	cout << "Done switching!" << endl;
	cout << "Checking mission!" << endl;
	if(!inter2->missShow) {
		cout << "Checking mission status..." << endl;
		cout << "Passing in: " << ply->mission << endl;
		inter2->levels[ply->mission]->status();
		cout << "Done checking mission status!" << endl;
		if(inter2->levels[ply->mission]->over) {
			cout << endl << "Mission accomplished!!" << endl << endl;
			inter2->missShow = true;
		}
	}
	cout << "Returning to main!" << endl;
}

void command::saveFile(interaction inter, player ply, world wld) {
	ofstream writefile(".player.save", ios::trunc);

	for(map<string, object*>::iterator it=inter.mO.begin();it!=inter.mO.end();it++) {
		writefile << it->first << " " << it->second->owner << endl;
	}

	writefile.close();
}

#endif
