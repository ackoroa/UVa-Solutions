#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int arrTable[92][9], tableIdx, row[9], origArr[9];

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
	int min = 10, temp;
	for (int i = 0; i < 92; i++) {
		temp = 0;
		for (int j = 1; j < 9; j++) {
			if (origArr[j] != arrTable[i][j])
				temp++;
		}
		if (temp < min)
			min = temp;
		if (min == 0)
			break;
	}
	return min;
}

int main() {
	int count = 0;
	preproc();

	while (scanf("%d %d %d %d %d %d %d %d", &origArr[1], &origArr[2],
			&origArr[3], &origArr[4], &origArr[5], &origArr[6], &origArr[7],
			&origArr[8]) != EOF) {
		count++;

		int ans = processCase();

		printf("Case %d: %d\n", count, ans);
	}

	return 0;
}
