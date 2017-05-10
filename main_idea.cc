//THIS CODE IS NOT PART OF THE PROJECT, IT IS ONLY FOR REFERENCE.

#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstdio>

using namespace std;

//die func
void die(string msg = "") {
	cout << "BAD INPUT" << endl;
	cerr << msg << endl;
	exit(0);
}

//holds values assigned to variables
vector<int> values(26, 256);

//'a' returns 0, b returns = 1..
int char_to_index(char c) {
	return 'a' - c;
}

//returns value stored in a variable and increments it by 1.
int get_value(char variable) {
	return values.at(char_to_index(variable))++;
}

//returns true if user let variable = some number between 0 and 255.
bool not_let(char variable) { 
	return values.at(char_to_index(variable)) > 255;
}

int main() { 
	//will store input here
	string line;
	//will dump trash here
	string dump;
	//will append msg here for errors.
	string err_msg = " ";
	
	//main loop (too lazy to add a tolower function, but should be done of course), if the text "quit" is anywhere in the string the loop breaks.
	while(line.find("quit") == string::npos && line.find("QUIT") == string::npos) {
		//read in the line
		getline(cin, line);
		
		//push the line into a stringstream
		stringstream ss;
		ss << line;
		
		//pull out the first word from the stringstream
		string word;
		ss >> word;

		if(word == "LET") {
			char variable;
			//pull out the next part of the stringstream, (expecting a char, but should do error checking too)
			ss >> variable;
			//throw away the next part of the stringstream (expecting an =) since we don't need to do anything with it.
			ss >> dump;
			if(dump != "=") die("bad format.");
			//finally, pull out the value we are letting the variable equal.
			int value = 256;
			ss >> value;
			
			//sort of a double negative, but if not not let basically means if we already let a variable equal some value..
			if(!not_let(variable)) {	
				err_msg = "Already let ";
				err_msg.push_back(variable);
				err_msg += " some value.";
				die(err_msg);
			}
			
			//We made it this far, so we should have good data, finally put the value into the appropriate index..
			cout << "LETTING " << variable << " equal " << value << endl;
			if(value > 255 || value < 0) die("out of range (0-255)");
			values.insert(values.begin() + char_to_index(variable), value);

			//this just confirms it was added to the vector, and the second call to get_value confirms it was incremented by 1 after getting the value.
			cout << get_value(variable) << endl;
			cout << get_value(variable) << endl;
			continue;
		}
		else {
			//ELSE IT IS PROBABLY AN EQUATION.
		}

	}

	cout << "quit" << endl;
	return 0;
}
