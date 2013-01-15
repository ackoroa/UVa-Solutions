#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int arrTable[92][9], tableIdx, row[9], scoreTable[9][9];

bool canPlace(int tryRow, int col) {
	for (int prevCol = 1; prevCol < col; prevCol++) {
		if (row[prevCol] == tryRow)
			return false;
		if (abs(row[prevCol] - tryRow) == abs(prevCol - col))
			return false;
	}
	return true;
}

void placeCol(int col) {
	int tryRow;

	if (col > 8) {
		memcpy(arrTable[tableIdx], row, 9 * 4);
		tableIdx++;
		return;
	} else {
		for (tryRow = 1; tryRow < 9; tryRow++) {
			if (canPlace(tryRow, col)) {
				row[col] = tryRow;

				placeCol(col + 1);
			}
		}
	}
}

void preproc() {
	tableIdx = 0;
	memset(row, 0, 9 * 4);
	placeCol(1);
}

int processCase() {
	int max = -1, temp;
	for (int i = 0; i < 92; i++) {
		temp = 0;
		for (int j = 1; j < 9; j++) {
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
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				scanf("%d", &scoreTable[i][j]);
			}
		}

		int ans = processCase();

		printf("%5d\n", ans);
	}

	return 0;
}
