#include <iostream>
#include <vector>
using namespace std;
void tolower(string& word) {
	for (auto& c: word)
		c = tolower(c);
}
//super smart code in main from tucker
//second attempt at super smart code from tucker
class Variables {
	private:
		vector<int> letters; //set to (26, 256) 
	public:
		Variables() : letters(26,256) {}
		void set(int num, char let);
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
