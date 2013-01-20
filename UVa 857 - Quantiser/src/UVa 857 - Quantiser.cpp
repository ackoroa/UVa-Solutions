#include <cstdio>
#include <vector>
using namespace std;

struct event {
	int on, note, m, b, t;
	event(int o, int n, int mx, int bx, int tx) {
		on = o;
		note = n;
		m = mx;
		b = bx;
		t = tx;
	}
};

int main() {
	int n;

	while (scanf("%d", &n), n > -1) {
		int on, note, m, b, t;
		vector<event> eventList;

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d %d", &on, &note, &m, &b, &t);

			t = ((t + 30) / 60) * 60;
			if (t == 480) {
				t = 0;
				b++;
				if (b == 5) {
					b = 1;
					m++;
				}
			}

			//printf("%d %d %d %d %d\n",on,note,m,b,t);
			event *e = new event(on, note, m, b, t);
			eventList.push_back(*e);
		}

		for (vector<event>::iterator ei = eventList.begin();
				ei != eventList.end(); ei++) {
			if (!ei->on)
				continue;

			for (vector<event>::iterator ej = ei + 1; ej != eventList.end();
					ej++) {
				if ((ei->note == ej->note) && (ei->on && !ej->on)) {
					if (ei->m == ej->m && ei->b == ej->b && ei->t == ej->t) {
						ei = eventList.erase(ei);
						ei--;
						ej--;
						ej = eventList.erase(ej);
						ej--;
					}
					break;
				}
			}
		}

		printf("%d\n", eventList.size());
		for (vector<event>::iterator it = eventList.begin();
				it != eventList.end(); it++) {
			printf("%d %d %d %d %d\n", it->on, it->note, it->m, it->b, it->t);
		}

	}
	printf("-1\n");

	return 0;
}
