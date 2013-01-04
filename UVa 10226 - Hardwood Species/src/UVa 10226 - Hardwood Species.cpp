#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;

	cin >> n;
	cin.ignore();
	cin.ignore();

	while (n > 0) {
		map<string, int> logbook;
		string name;
		int total;

		total = 0;
		while (true) {
			getline(cin, name);
			if (name.empty())
				break;

			if (logbook.count(name) == 0) {
				logbook[name] = 0;
			}
			logbook[name] = logbook[name] + 1;
			total++;
		}

		map<string, int>::iterator it;
		for (it = logbook.begin(); it != logbook.end(); it++) {
			cout << (*it).first << " ";
			printf("%.4lf\n", (double)(*it).second/(double)total *100.0);
		}
		n--;
		if(n>0) cout << endl;
	}

	return 0;
}
