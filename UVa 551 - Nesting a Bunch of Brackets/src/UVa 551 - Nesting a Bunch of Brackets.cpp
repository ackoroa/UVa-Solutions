#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

stack<char> checker;

bool isOpening(char c) {
	if (c == '(' || c == '[' || c == '<' || c == '{')
		return true;
	return false;
}

bool isClosing(char c) {
	if (c == ')' || c == ']' || c == '>' || c == '}')
		return true;
	return false;
}

int main() {
	char s[3001];
	while (gets(s)) {
		int count = 0;
		int len = strlen(s), i;
		for (i = 0; i < len; i++) {
			count++;
			if (isOpening(s[i])) {
				if (s[i] == '(' && s[i + 1] == '*') {
					checker.push('*');
					i++;
				} else {
					checker.push(s[i]);
				}
			} else if (isClosing(s[i]) || (s[i] == '*' && s[i + 1] == ')')) {
				if (checker.empty())
					break;
				if (s[i] == '*') {
					if (checker.top() != '*') {
						break;
					}
					checker.pop();
					i++;
				} else if (s[i] == ')') {
					if (checker.top() != '(') {
						break;
					}
					checker.pop();
				} else if (s[i] == ']') {
					if (checker.top() != '[') {
						break;
					}
					checker.pop();
				} else if (s[i] == '>') {
					if (checker.top() != '<') {
						break;
					}
					checker.pop();
				} else if (s[i] == '}') {
					if (checker.top() != '{') {
						break;
					}
					checker.pop();
				}
			}
		}

		if (i < len || !checker.empty()) {
			if (i>=len && !checker.empty())
				count++;
			printf("NO %d\n", count);
		} else
			printf("YES\n");

		while (!checker.empty())
			checker.pop();
	}

	return 0;
}
