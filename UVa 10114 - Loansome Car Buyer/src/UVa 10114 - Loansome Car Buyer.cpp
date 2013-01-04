#include <iostream>
#include <vector>
using namespace std;

int main() {
	int loanDur, nRec;
	double downPayment, loan, decP[101];

	while (true) {
		cin >> loanDur >> downPayment >> loan >> nRec;
		if (loanDur < 0)
			break;

		int m;
		double p;
		while (nRec--) {
			cin >> m >> p;
			for (int i = m; i < 101; i++)
				decP[i] = p;
		}

		int now = 0;
		double monthlyPayment = loan / loanDur;
		double curVal = (loan + downPayment) * (1 - decP[0]);
		double curLoan = loan;
		while (curVal < curLoan) {
			now++;
			curLoan -= monthlyPayment;
			curVal = curVal * (1-decP[now]);
		}

		cout << now << " month";
		if (now != 1)
			cout << "s";
		cout << endl;
	}

	return 0;
}
