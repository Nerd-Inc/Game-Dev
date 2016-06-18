#ifndef SET_H_INCLUDED_
#define SET_H_INCLUDED_
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "../Codes/object.hpp"
#include "../Codes/player.hpp"
using namespace std;

void loadFile(interaction&, player&);

vector<string> seperate(string input, bool show = false)
{
	//add each character to a string
	//if character is a symbol, keep adding till end symbol is met
	map<char, bool> char_syms_start, char_syms_stop;
	char_syms_start['['] = true;
	char_syms_start['{'] = true;
	char_syms_start['('] = true;
	char_syms_stop[']'] = true;
	char_syms_stop['}'] = true;
	char_syms_stop[']'] = true;
	string temp;
	bool flag = false;
	vector<string> ret;
	for(unsigned int i=0;i<input.size();i++){
		//cout << "Working with: " << input[i] << endl;
		if(flag) {
			if(char_syms_stop[input[i]]) {
				//cout << "Termination found..." << endl;
				temp += input[i];
				flag = false;
				//continue;
			} else temp += input[i];
		}
		else if(char_syms_start[input[i]]) {
			//cout << "Container found..." << endl;
			temp += input[i];
			flag = true;
		}
		else if(input[i] == ' '){
			ret.push_back(temp);
			temp.erase();
		} else temp += input[i];
	} ret.push_back(temp);
	
	return ret;
}

bool ifFile(string name) {
	bool fFile = false;
	//check if file exist....
	system("ls -a >> .temp.txt");
	ifstream readfile(".temp.txt");
	string temp;
	vector<string> file;

	while(readfile >> temp) file.push_back(temp);
	//bool fFile = false;

	system("rm .temp.txt");

	for(unsigned int i=0;i<file.size();i++) {
		if(file[i] == name) {
			//cout << "Loading games modules..." << endl << endl;
			fFile = true;
			break;
		}
	}

	file.clear(); //so as to use later to read other files
	readfile.close();
	
	return fFile;
}

void loadFile(interaction& inter, player& ply) {
	system("clear");
	cout << "LOADING..." << endl;
	cout << "-------" << endl << endl;

	if(ifFile(".player.save")) {
		string temp;
		vector<string> file;
		map<string, string> objOwner;
		ifstream readfile1(".player.save");
		while(readfile1 >> temp) file.push_back(temp);

		for(unsigned int i=0;i<4;i+=2) objOwner.insert(make_pair(file[i], file[i+1])); //objects are being initialized here
		ply.mission = atoi(file[file.size() -1].c_str()); //put mission here
		cout << "Mission set to: " << ply.mission << " at: " << &ply.mission << endl;
		
		for(map<string, string>::iterator it=objOwner.begin();it!=objOwner.end();it++) {
			//cout << it->first << " --- " << it->second << endl;
			//inter.mO.insert(make_pair(it->first, it->second))
			inter.values.push_back(it->first);
			inter.values.push_back(it->second);
			//cout << "done.." << endl;
		}
		inter.ini(false);
	} else {
		ply.mission = 1;
		inter.ini(true);
	}
	//cout << "Object mapper: " << inter.mO.size() << endl;
}

#endif
