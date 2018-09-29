// Robyn Yates
// CSCI 4100 Assignment 1
// Source file for the Cat class
// Implements a command line utility that displays the
// contents of a file.

// Add any additional required #include statements here
#include "Cat.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Cat::main(int argc, string argv[]) {
	// YOUR CODE HERE

	if (argc != 2) {
		cout << "usage: cat <filename>" << endl;
		return 1;
	}
	else {
		ifstream myFile;
		string line;
		myFile.open(argv[1]);
		if (myFile.is_open()) {
			while (getline (myFile, line)) {
				cout << line << '\n';
			}
			myFile.close();
			return 0;
		}
		else {
			cout << "error: file not found" << endl;
			return 1;
		}
	}

	return 0;
}
