#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int arrTable[92][8], tableIdx, row[8], origArr[8];
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
	int min = 10, temp;
	for (int i = 0; i < 92; i++) {
		temp = 0;
		for (int j = 0; j < 8; j++) {
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

	while (scanf("%d %d %d %d %d %d %d %d", &origArr[0], &origArr[1],
			&origArr[2], &origArr[3], &origArr[4], &origArr[5], &origArr[6],
			&origArr[7]) != EOF) {
		count++;

		for (int i = 0; i < 8; i++)
			origArr[i]--;

		int ans = processCase();
		printf("Case %d: %d\n", count, ans);
	}

	return 0;
}
