#ifndef COMMAND_H_INCLUDED_
#define COMMAND_H_INCLUDED_
#include "../Other Files/values.hpp"
#include "../Codes Expanded/exPlayer.hpp"
#include "../Codes Expanded/exWorld.hpp"
#include "missions.hpp"
using namespace std;

class command {
public:
	string com_input, pObject_take;
	vector<string>split_comInput;
	void input(), ini(), saveFile(interaction, player, world);
	command();
};

class execute {
public:
	command com1;
	player *ply;
	world wld;
	interaction* inter;
	interaction2* inter2;

	void input(command, player&, world, interaction&, interaction2&), ini();
};

#endif

//func_errors -> defines the various errors in the program
