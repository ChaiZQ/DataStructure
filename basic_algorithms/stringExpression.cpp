#include <iostream>
#include <stack>
using namespace std;

//only + - and ()

int SimpleCalculate(string str){
	int res = 0;
	int number=0;
	int sign = 1;
	stack<int> result;
	for(int i=0;i<str.size();++i){
		if (str[i] >= '0'&&str[i] <= '9') {
			number = 10 * number + str[i] - '0';
		}
		else if (str[i] == '+') {
			res +=sign*number;
			sign = 1;
			number = 0;
		}
		else if (str[i] == '-') {
			res += sign*number;
			sign = -1;
			number = 0;
		}
		else if (str[i] == '(') {
			result.push(res);
			result.push(sign);
			res = 0;
			sign = 1;
		}
		else if (str[i] == ')') {
			res += sign*number;
			number = 0;
			res *= result.top();
			result.pop();
			res = result.top() + res;
			result.pop();
		}
	}
	if (number != 0)
		res = res + sign*number;
	return res;
}

bool logicCalculate(string str) {
	bool res = 1;
	bool cur = 1;
	char op=-1;
	stack<bool> result;
	stack<char> ops;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] =='1' || str[i]=='0') {
			cur = str[i] == '1';
			if (op == '!') {
				cur = !cur;
				res = result.top();
				result.pop();
				op = ops.top();
				ops.pop();
			}
			if (op != -1) {
				if (op == '|')
					res = res | cur;
				else if (op == '&')
					res = res & cur;

				op = -1;
			}
		}
		else if (str[i] == '(') {
			result.push(res);
			ops.push(op);
			op = -1;
			res = 1;
		}
		else if (str[i] == ')') {
			op = ops.top();
			cur = res;
			res = result.top();
			if (op == '|')
				res = res | cur;
			else if (op == '&')
				res = res & cur;

		}
		else if (str[i] == '!') {
			result.push(res);
			res = 1;
			ops.push(op);
			op = str[i];
		}
		else {
			op = str[i];
		}
	}

	return res;
}

int main(int argc, char**argv) {

	//cout << SimpleCalculate("40-(10+20)") << endl;
	cout << logicCalculate("(!((!0)|(1&0))&(!1))") << endl;
	system("pause");
	return 0;
}