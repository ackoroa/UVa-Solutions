#include <cstdio>
#include <stack>
#include <sstream>
using namespace std;

int main() {
	stack<int> brChck, capChck;
	char s[1000000];

	while (gets(s)) {
		stringstream ss(s);
		int d;
		bool err = false;
		while (ss >> d) {
			if (!err) {
				if (d < 0) {
					d = -d;

					brChck.push(d);

					if (capChck.empty()) {
						capChck.push(d);
					} else {
						int t = capChck.top();
						capChck.pop();

						t = t - d;
						if (t <= 0) {
							err = true;
							break;
						}
						capChck.push(t);
						capChck.push(d);
					}
				} else {
					if (brChck.empty() || brChck.top() != d) {
						err = true;
						break;
					}
					brChck.pop();

					capChck.pop();
				}
			}
		}
		if (!brChck.empty())
			err = true;

		if (err)
			printf(":-( Try again.\n");
		else
			printf(":-) Matrioshka!\n");

		while (!brChck.empty())
			brChck.pop();
		while (!capChck.empty())
			capChck.pop();
	}

	return 0;
}
