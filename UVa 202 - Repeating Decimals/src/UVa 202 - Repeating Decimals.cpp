#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
	int a, b;
	int result, remainder, index;
	map<int, int> remainderIndex;
	vector<int> decimalDigits;

	while (scanf("%d %d", &a, &b) != EOF) {
		remainderIndex.clear();
		decimalDigits.clear();
		index = 0;

		result = a / b;
		remainder = a % b;
		while (!remainderIndex.count(remainder)) {
			remainderIndex[remainder] = index++;
			result = remainder * 10 / b;
			decimalDigits.push_back(result);
			remainder = (remainder * 10) % b;
		}

		int cycleStartIndex = remainderIndex[remainder];
		int nCurDigit = 0;

		printf("%d/%d = %d.", a, b, a / b);
		for (; nCurDigit < cycleStartIndex && nCurDigit < 50; nCurDigit++) {
			printf("%d", decimalDigits[nCurDigit]);
		}
		printf("(");
		for (; nCurDigit < index && nCurDigit < 50; nCurDigit++) {
			printf("%d", decimalDigits[nCurDigit]);
		}

		if (nCurDigit >= cycleStartIndex) {
			if (nCurDigit < index)
				printf("...");
			printf(")\n");
		}
		printf("   %d = number of digits in repeating cycle\n\n",
				index - cycleStartIndex);
	}

	return 0;
}
