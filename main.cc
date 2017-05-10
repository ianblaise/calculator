#include <iostream>
#include <vector>
using namespace std;
void tolower(string& word) {
	for (auto& c: word)
		c = tolower(c);
}
//Bell: wasn't completely sure how to implement this do_math, is it supposed to get called on the vector/queue that holds the problem?
//if I'm on the wrong track down below, feel free to change it up or you can just comment it and I'll fix it  -Tucker

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


int main () {
	Variables vari;
	string temp;
	getline(cin, temp);
	tolower(temp); //keep input consistant and easy, lowercase
	vector <char> var(temp.begin(),temp.end()); //trying this out, taking from cin, pushing into a vector
	

	for (unsigned int i = 0; i < var.size(); i ++) { //this is just so i can test whats going in the vector
	cerr << var.at(i) << endl;
	}

	if (var.at(0) == 'l' && var.at(1) == 'e' && var.at(2) == 't') { //check for "let" to set variables
		if (isalpha(var.at(4)) && isdigit(var.at(8)) && var.at(6) == '=') { //check to make sure that after "let" everything is in good format
			vari.set(var.at(4),var.at(6)); // this is throwing vector range exception, ask bell about how to use 26/256 askii	
		}
		else cout << "BAD INPUT\n";
	}


//	char operat;
//	string operation;
//	while(cin){
//		cin >> operat;
//	}
//	cout << "this is a calcutalor it will do something";
	return 0;
}
