#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;
//I changed up input to go into a vector so I can iterate through the entire input for error checks
//Only thing I could not fix was checking the end of the vector for "=" sign, you can see down in main I attempted to work backwards through the vector, but I couldn't get that to work, also, the variables are not incrementing by 1 every time we use them, I don't think the returning let++ is working up top
//-Tucker

//moved die to the top
void die() {
	cout << "BAD INPUT\n";
	exit(EXIT_FAILURE);
}
void tolower(string& word) {
	for (auto& c : word)
		c = tolower(c);
}
class Variables {
  private:
	vector<int> letters; //set to (26, 256)
  public:
	Variables() : letters(26, 256) {}
	void set(int num, char let) {
		if (let < 'a' || let > 'z') die();
		letters.at(let - 'a') = num;
	}
	int get(char let) {
		int number = letters.at(let - 'a');
		//letters.at(let - 'a') = letters.at(let - 'a') + 1;
		set(letters.at(let - 'a') +1, let);
		return number;
	}
};
int string_to_int(string thing, Variables vari) {
	int number = 0;
	if (thing.length() > 1) { //if string is longer than one must be a number
		int length = thing.length() - 1;
		for (int i = 0; i <= length; i++) {
			number += (thing.at(i) - '0') * pow(10, length - i);
		}
	} else { //check if number or variable
		char i = thing.at(0);
		if (isalpha(i)) {
			number = vari.get(i);
		} else {
			if (i > '0' && i < '9') number = i - '0';
		}
	}
	return number;
}
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
	number = string_to_int(thing, vari); //converts string thing to a number
	equals = number;
	while (stream) {
		stream >> thing;
		if (thing.length() > 1) die();
		i = thing.at(0);
		if (i == '+') { //ADD
			stream >> thing;
			number = string_to_int(thing, vari);
			equals += number;//add the next to equals
		} else if (i == '-') { //SUBTRACT
			stream >> thing;
			number = string_to_int(thing, vari);
			equals -= number;//subtract the next from equals
		} else if (i == '*') { //MULTIPLY
			stream >> thing;
			number = string_to_int(thing, vari);
			equals *= number;//multiply equals by next
		} else if (i == '/') { //DEVIDE
			stream >> thing;
			number = string_to_int(thing, vari);
			equals /= number;//divide equals by next
		} else if (i == '^') { //POW
			stream >> thing;
			number = string_to_int(thing, vari);
			equals = pow(equals, number); //equals pow(next)
		} else if (i == '%') { //MOD
			stream >> thing;
			number = string_to_int(thing, vari);
			equals %= number;//equals mod next
		} else {
			//die();
		}
		//if (equals > 255) die();
	}
	return equals;
}

int char_to_index(char c) {
	return c - 'a';
}

int main() {
	Variables vari;
	string temp, s1, s2, s3, s4;

	while (cin) {
		getline(cin, temp);
		tolower(temp);
		stringstream ss(temp);
		vector <string> mvec;
		int intd = 0;
		char a;
		while (ss) {
			string s;
			ss >> s;
			mvec.push_back(s);
			mvec.push_back(" ");
		}
		for (unsigned int i = 0; i < mvec.size(); i++) {
			if (mvec.at(i) == "quit") return 0;
		}
		if (mvec.at(0) == "let") {
			intd = atoi(mvec.at(6).c_str()); // changing string to int to put in Variable class
			a = mvec.at(2).at(0); // changing string to char to put in variables class
			if (intd > 255 || intd < 0) die();
			if (mvec.at(2).size() > 1) die();
			vari.set(intd, a);
			continue;
		}
		else if (mvec.at(0) != "let") {
			//else if (mvec.at(0).at(0)) {
			for (unsigned int i = 0; i < (mvec.size()); i++) {
				for (unsigned int j = 0; j < mvec.at(i).size(); j++ ){
					if (isalpha(mvec.at(i).at(j)))
						if (mvec.at(i).size() > 1)
							die();
				}
			}
		}
		if (temp.at(temp.length()-1) != '=') die(); 
			/*for (unsigned i = mvec.size(); i-- > 0;){
			  if (mvec.at(i) == " ")
			  continue;
			  else if(mvec.at(i) == "=") {
			//	cout << mvec.at(i);
			break;
			}
			else die();//else if (mvec.at(i) == "="){
			//	break;
			//}
			//else die();
			*/
			//		cout << "mvec.at: " << i << " = " << mvec.at(i) << endl;
			//	}
		cout << do_math(temp, vari) << endl;
		}
		return 0;
		}
