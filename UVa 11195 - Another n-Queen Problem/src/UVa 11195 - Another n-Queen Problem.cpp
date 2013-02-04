#include <cstdio>
using namespace std;

bool board[14][14];

int ans, n;

void placeCol(int col, int rw, int ld, int rd) {
	if ((((1 << n) - 1) & rw) == ((1 << n) - 1)) {
		ans++;
		return;
	}

	int pos = ((1 << n) - 1) & ~(rw | ld | rd);
	for (int tryRow = 0; tryRow < n; tryRow++) {
		if (1 & (pos >> tryRow) & board[tryRow][col]) {
			placeCol(col + 1, rw | (1 << tryRow), (ld | (1 << tryRow)) << 1,
					(rd | (1 << tryRow)) >> 1);
		}
	}
}

int main() {
	char ch;
	int count = 0;

	while (scanf("%d", &n), n) {
		count++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%c", &ch);
				board[i][j] = ch == '.' ? 1 : 0;
				if (ch == '\n')
					j--;
			}
		}
		ans = 0;
		placeCol(0, 0, 0, 0);
		printf("Case %d: %d\n", count, ans);
	}

	return 0;
}
