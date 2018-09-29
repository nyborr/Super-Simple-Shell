// Robyn Yates
// CSCI 4100 Assignment 1
// This program implements a simple shell

#include <iostream>
#include <string>
#include "Cat.hpp"
using namespace std;

// Maximum number of arguments (including command) allowed
// in a command line. 
const int MAX_ARGS = 16;

int scanCommandLine(string cmd, string argv[]);

int main()
{
	string command;
	string argv[MAX_ARGS];
	Cat cat;

	while (command != "exit") {
		cout << "$ ";
		getline(cin, command);

		int y = scanCommandLine(command, argv);

		if (argv[0] == "cat" && y > 0) {
			cat.main(y, argv);
		}
		else if (command != "exit" && command != "cat" && y > 0) {
			cout << argv[0] << ": command not found" << endl;
			argv->clear();
		}
	}
	system("Pause");
	return 0;
}


int scanCommandLine(string cmd, string argv[])
{
	int argc = 0;
	size_t start = 0;
	size_t end = 0;
	string arg;

	while (end != string::npos && argc < MAX_ARGS) {
		start = cmd.find_first_not_of(" \t", end);
		if (start == string::npos)
			break;
		end = cmd.find_first_of(" \t", start);
		argv[argc] = cmd.substr(start, end - start);
		argc++;
	}
	return argc;
}