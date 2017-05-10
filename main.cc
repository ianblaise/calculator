#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;
void tolower(string& word) {
	for (auto& c: word)
		c = tolower(c);
}
//Bell: wasn't completely sure how to implement this do_math, is it supposed to get called on the vector/queue that holds the problem?
//if I'm on the wrong track down below, feel free to change it up or you can just comment it and I'll fix it  -Tucker
//your doing good, call do math with a string of the equation like "x + 2" leave the spaces in if possible
//i need the space to be able to tell the difference between the char and the num -Bell

//askii goes up to 255 so it should work all the way with chars?
//unsigned chars go to 255
int do_math(string equn) { //can change if you want to use queue
	int equals = 0;
	for (unsigned char i: equn) {
		if (i == ' ') continue;
		if (!isalpha(i)) {//might not work because askii for '+' is a number...
			if (i == '+') ;//add the next to equals
			else if (i == '-') ;//subtract the next from equals
			else if (i == '*') ;//multiply equals by next
			else if (i == '/') ;//divide equals by next
			else if (i == '^') ;//equals pow(next)
			else if (i == '%') ;//equals mod next
			else {//should only run the first time? 
				equals = i;
			}
		} else {//should only run the first time variable
			equals = i;
		}
	}
	return equals;
}

class Variables {
	private:
		vector<int> letters; //set to (26, 256) 
	public:
		Variables() : letters(26,256) {}
		void set(int num, char let) {
			letters.at(let - 'a') = num;
		}
		int get(char let) {return letters.at(let);}
};

void die(){
	cout << "BAD INPUT\n";
	exit(EXIT_FAILURE);
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
		ss >> s1 >> s2 >> s3 >> s4;

		if (s1 == "let") {

			int intd = atoi(s4.c_str()); // changing string to int to put in Variable class	
			char a = s2.at(0); // changing string to char to put in variables class
			
			if (intd > 255 || intd < 0) die();
			if (s2.size() > 1) die();
		//	if (!isalpha(s2)) die(); figure a way to check for letters or numbers in the wrong spot for let statement
			if (vari.get(char_to_index(a)) != 256) {
				cout << "Variable already set\n";
				continue;
			}

			vari.set(intd,a);
		}
		//instead of else if's maybe try and catch

		else if (temp == "query"){
			for (auto i = 0; i < 26; i++)
			cout << vari.get(i) << endl;//throwing out of range, tuckers a noob and doesn't understand ascii
		}
		else if (isdigit(s1[0])) { //in the works
			cout << do_math(temp) << endl;
		}
		else cout << "BAD INPUT\n";
	}

	/*
	//Tucker, you have the parameters backwards, which is probably why it's throwing an exception.
	//set's first parameter is the integer value and the second parameter is the variable char value.
	//Also, consider using stringstream or cin instead of checking char by char
	// -- Ian
	}
	}

*/
	return 0;
}
