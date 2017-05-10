#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void die(string msg = "") {
	cout << "BAD INPUT" << endl;
	cerr << msg << endl;
	exit(0);
}

class var { 
	public:
		
	private:
		char letter;
		int value;
};

vector<int> values(26, 256);

int char_to_index(char c) {
	return 97 - c;
}

int get_value(char variable) {
	return values.at(char_to_index(variable))++;
}

bool not_let(char variable) { 
	return values.at(char_to_index(variable)) > 255;
}

int main() { 
	string line;
	string dump;
	string err_msg = " ";
	while(line.find("quit") == string::npos && line.find("QUIT") == string::npos) {
		getline(cin, line);
		
		stringstream ss;
		ss << line;
		
		string word;
		ss >> word;
		if(word == "LET") {
			char variable;
			ss >> variable;
			int value;
			ss >> dump;
			if(dump != "=") die("bad format.");
			ss >> value;
			
			if(!not_let(variable)) {	
				err_msg = "Already let ";
				err_msg.push_back(variable);
				err_msg += " some value.";
				die(err_msg);
			}
			
			cout << "LETTING " << variable << " equal " << value << endl;
			if(value > 255 || value < 0) die("out of range (0-255)");
			values.insert(values.begin() + char_to_index(variable), value);
			cout << get_value(variable) << endl;
			cout << get_value(variable) << endl;
			continue;
		}
		

	}

	cout << "quit" << endl;
	return 0;
}
