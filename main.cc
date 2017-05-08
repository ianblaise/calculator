#include <iostream>
#include <vector>
using namespace std;
void tolower(string& word) {
	for (auto& c: word)
		c = tolower(c);
}
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

//super smart code in main from tucker
//second attempt at super smart code from tucker
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
	char operat;
	string operation;
	while(cin){
		cin >> operat;
	}
	cout << "this is a calcutalor it will do something";
	return 0;
}
