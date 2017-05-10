//THIS CODE IS NOT PART OF THE PROJECT, IT IS ONLY FOR REFERENCE

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> numbers;
	queue<char> operators;

	//add some random numbesr to the queue
	numbers.push(5);
	numbers.push(2);
	numbers.push(8);
	numbers.push(60);
	numbers.push(9);
	//add some operators to the queue
	operators.push('+');
	operators.push('-');
	operators.push('*');
	operators.push('/');

	//initialize some variables
	int rhs, lhs;
	rhs = lhs = 0;
	char operat = ' ';

	//this checks valid input.. if this is false it means they typed like 5 5 + 1 - 2 or something instead of 5 * 5 + 1 - 2
	if(!(numbers.size() == operators.size() + 1)) {
		cout << "BAD STUFF BRO." << endl; 
		return 0;
	}

	//set ans to the first number in queue, making it the left hand side essentially.
	lhs = numbers.front();
	numbers.pop();

	while(!numbers.empty() && !operators.empty()) {
		//set the rhs to next value in queue.
		rhs = numbers.front();
		numbers.pop();
		
		//set the operator
		operat = operators.front();
		operators.pop();
	
		//perform the operation
		switch(operat) {
			case '+':
				lhs += rhs;
				break;
			case '-':
				lhs -= rhs;
				break;
			case '*':
				lhs *= rhs;
				break;
			case '/':
				lhs /= rhs;
				break;
			default:
				break;
		}
		cout << lhs << endl;
	}
	return 0;
}
