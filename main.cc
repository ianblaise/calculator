#include <iostream>
#include <vector>
using namespace std;
void tolower(string word) {
}
//super smart code in main from tucker
//second attempt at super smart code from tucker
class Variables {
	private:
		vector<int> letters; //set to (26, 256) 
	public:
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
