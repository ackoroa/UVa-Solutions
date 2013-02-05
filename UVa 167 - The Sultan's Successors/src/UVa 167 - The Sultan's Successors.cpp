#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int arrTable[92][8], tableIdx, row[8], scoreTable[8][8];
bitset<30> rw, ld, rd;

void placeCol(int col) {
	int tryRow;

	if (col >= 8) {
		memcpy(arrTable[tableIdx], row, 8 * 4);
		tableIdx++;
		return;
	} else {
		for (tryRow = 0; tryRow < 8; tryRow++) {
			if (!rw[tryRow] && !ld[tryRow - col + 8 - 1] && !rd[tryRow + col]) {
				row[col] = tryRow;

				rw[tryRow] = ld[tryRow - col + 8 - 1] = rd[tryRow + col] = true;
				placeCol(col + 1);
				rw[tryRow] = ld[tryRow - col + 8 - 1] = rd[tryRow + col] =
						false;
			}
		}
	}
}

void preproc() {
	tableIdx = 0;
	memset(row, 0, 8 * 4);
	placeCol(0);
}

int processCase() {
	int max = -1, temp;
	for (int i = 0; i < 92; i++) {
		temp = 0;
		for (int j = 0; j < 8; j++) {
			int r, c;
			c = j;
			r = arrTable[i][c];
			temp += scoreTable[r][c];
		}
		if (temp > max)
			max = temp;
	}
	return max;
}

int main() {
	int n;
	preproc();

	scanf("%d", &n);

	while (n--) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &scoreTable[i][j]);
			}
		}

		int ans = processCase();

		printf("%5d\n", ans);
	}

	return 0;
}
