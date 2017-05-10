#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;
//moved die to the top
void die() {
	cout << "BAD INPUT\n";
	exit(EXIT_FAILURE);
}
void tolower(string& word) {
	for (auto& c: word)
		c = tolower(c);
}
class Variables {
	private:
		vector<int> letters; //set to (26, 256) 
	public:
		Variables() : letters(26,256) {}
		void set(int num, char let) {
			if (let < 'a' || let > 'z') die();
			letters.at(let - 'a') = num;
		}
		int get(char let) {return letters.at(let++);}
};
//Bell: wasn't completely sure how to implement this do_math, is it supposed to get called on the vector/queue that holds the problem?
//if I'm on the wrong track down below, feel free to change it up or you can just comment it and I'll fix it  -Tucker
//your doing good, call do math with a string of the equation like "x + 2" leave the spaces in if possible
//i need the space to be able to tell the difference between the char and the num -Bell

//askii goes up to 255 so it should work all the way with chars?
//unsigned chars go to 255
int do_math(string equn, Variables vari) { //can change if you want to use queue
	int equals = 0;
	int number = 0;
	string thing;
	char i;
	stringstream stream(equn);
	stream >> thing;
	if (thing.length() > 1) { //if string is longer than one must be a number
		int length = thing.length();
		for (int i = 0; i < length; i++) {
			number += pow(10,length-(i+1)) * thing.at(i);
		}
	} else { //check if number or variable
		i = thing.at(0);
		if (isalpha(i)) {
			number = vari.get(i);
		} else {
			if ((int)i < 10) number = i;
		}
	}
	equals = number;
	while (stream) {
		stream >> thing;
		if(thing.length() > 1) die();
		i = thing.at(0);
		if (i == '+') { //ADD
			stream >> thing;
			if (thing.length() > 1) { //if string is longer than one must be a number
				int length = thing.length();
				for (int i = 0; i < length; i++) {
					number += pow(10,length-(i+1)) * thing.at(i);
				}
			} else { //check if number or variable
				i = thing.at(0);
				if (isalpha(i)) {
					number = vari.get(i);
				} else {
					if ((int)i < 10) number = i;
				}
			}
			equals += number;//add the next to equals
		} else if (i == '-') { //SUBTRACT
			stream >> thing;
			if (thing.length() > 1) { //if string is longer than one must be a number
				int length = thing.length();
				for (int i = 0; i < length; i++) {
					number += pow(10,length-(i+1)) * thing.at(i);
				}
			} else { //check if number or variable
				i = thing.at(0);
				if (isalpha(i)) {
					number = vari.get(i);
				} else {
					if ((int)i < 10) number = i;
				}
			}
			equals -= number;//subtract the next from equals
		} else if (i == '*') { //MULTIPLY
			stream >> thing;
			if (thing.length() > 1) { //if string is longer than one must be a number
				int length = thing.length();
				for (int i = 0; i < length; i++) {
					number += pow(10,length-(i+1)) * thing.at(i);
				}
			} else { //check if number or variable
				i = thing.at(0);
				if (isalpha(i)) {
					number = vari.get(i);
				} else {
					if ((int)i < 10) number = i;
				}
			}
			equals *= number;//multiply equals by next
		} else if (i == '/') { //DEVIDE
			stream >> thing;
			if (thing.length() > 1) { //if string is longer than one must be a number
				int length = thing.length();
				for (int i = 0; i < length; i++) {
					number += pow(10,length-(i+1)) * thing.at(i);
				}
			} else { //check if number or variable
				i = thing.at(0);
				if (isalpha(i)) {
					number = vari.get(i);
				} else {
					if ((int)i < 10) number = i;
				}
			}
			equals /= number;//divide equals by next
		} else if (i == '^') { //POW
			stream >> thing;
			if (thing.length() > 1) { //if string is longer than one must be a number
				int length = thing.length();
				for (int i = 0; i < length; i++) {
					number += pow(10,length-(i+1)) * thing.at(i);
				}
			} else { //check if number or variable
				i = thing.at(0);
				if (isalpha(i)) {
					number = vari.get(i);
				} else {
					if ((int)i < 10) number = i;
				}
			}
			equals = pow(equals,number);//equals pow(next)
		} else if (i == '%') { //MOD
			stream >> thing;
			if (thing.length() > 1) { //if string is longer than one must be a number
				int length = thing.length();
				for (int i = 0; i < length; i++) {
					number += pow(10,length-(i+1)) * thing.at(i);
				}
			} else { //check if number or variable
				i = thing.at(0);
				if (isalpha(i)) {
					number = vari.get(i);
				} else {
					if ((int)i < 10) number = i;
				}
			}
			equals %= number;//equals mod next
		} else {//should only run the first time? 
			die();
		}
		if (equals > 255) die();
	}
	return equals;
}

int char_to_index(char c) {
	return c - 'a';
}

int main () {
	Variables vari;
	string temp, s1, s2, s3, s4;

	while (cin) {
		getline(cin, temp);
		tolower(temp); 
		stringstream ss(temp);
		ss >> s1 >> s2 >> s3 >> s4;//while(ss) {vector<string> push_back()} to hold more input -Bell
		
		if (temp == "quit")
			return 0;
		else if (temp.substr(0,3) == "let") {

			int intd = atoi(s4.c_str()); // changing string to int to put in Variable class	
			char a = s2.at(0); // changing string to char to put in variables class
			
			if (intd > 255 || intd < 0) die();
			if (s2.size() > 1) die();
		//	if (!isalpha(s2)) die(); figure a way to check for letters or numbers in the wrong spot for let statement
			if (vari.get(char_to_index(a)) != 256) {
				cout << "Can't redeclare variable\n";
				die();
			}

			vari.set(intd,a);
		}
		//instead of else if's maybe try and catch

		else if (temp == "query"){
			for (auto i = 0; i < 26; i++)
			cout << vari.get(i) << endl;//throwing out of range, tuckers a noob and doesn't understand ascii
		}
		else  { //in the works
			cout << do_math(temp,vari) << endl;
		}
	}

	return 0;
}
