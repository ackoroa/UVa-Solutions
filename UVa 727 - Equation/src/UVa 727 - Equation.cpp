#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char c) {
	if (c == '(' || c == ')')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	return -1;
}

void pushOp(stack<char> &op, char token, char postfix[], int &idx) {
	if (op.empty() || precedence(op.top()) < precedence(token)) {
		op.push(token);
	} else {
		while (!op.empty() && (precedence(op.top()) >= precedence(token))) {
			postfix[idx] = op.top();
			idx++;
			op.pop();
		}
		op.push(token);
	}
}

int main() {
	int n;
	int count = 0;

	cin >> n;
	cin.ignore();
	cin.ignore();

	while (n--) {
		count++;
		if(count >1) cout << endl;

		stack<char> op;
		char postfix[51];
		string token;
		int idx = 0;

		while (true) {
			getline(cin, token);
			if (token.length() == 0 || !cin)
				break;

			if (isdigit(token.at(0))) {
				postfix[idx] = token.at(0);
				idx++;
			} else if (token.at(0) == ')') {
				while (op.top() != '(') {
					postfix[idx] = op.top();
					idx++;
					op.pop();
				}
				op.pop();
			} else if (token.at(0) == '(') {
				op.push('(');
			} else {
				pushOp(op, token.at(0), postfix, idx);
			}
		}

		while (!op.empty()) {
			postfix[idx] = op.top();
			idx++;
			op.pop();
		}
		postfix[idx] = '\0';

		cout << postfix << endl;
	}

	return 0;
}
