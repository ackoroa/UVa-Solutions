#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
	int n;
	map<string, int> logbook;
	char name[35];

	scanf("%d\n\n", &n);
	while (n--) {
		int total = 0;

		total = 0;
		while (gets(name)) {
			if (strlen(name) == 0)
				break;

			if (logbook.count(string(name)) == 0) {
				logbook[string(name)] = 1;
			} else
				logbook[string(name)] = logbook[string(name)] + 1;

			total++;
		}

		map<string, int>::iterator it;
		for (it = logbook.begin(); it != logbook.end(); it++) {
			printf("%s %.4lf\n", (*it).first.data(),
					(double) (*it).second / (double) total * 100.0);
		}
		if (n > 0){
			printf("\n");
			logbook.clear();
		}
	}

	return 0;
}
