#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int TC, givenRow, givenCol, row[9], lineCounter;

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

	if (col > 8 && row[givenCol] == givenRow) {
		printf("%2d      %d", ++lineCounter, row[1]);
		for (int j = 2; j < 9; j++) {
			printf(" %d", row[j]);
		}
		printf("\n");
		return;
	} else {
		for (tryRow = 1; tryRow < 9; tryRow++) {
			if (canPlace(tryRow, col)) {
				row[col] = tryRow;

				if (col == givenCol && row[col] != givenRow)
					continue;
				else
					placeCol(col + 1);
			}
		}
	}
}

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &givenRow, &givenCol);

		for (int i = 0; i < 9; i++) {
			row[i] = 0;
		}
		lineCounter = 0;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		placeCol(1);

		if (TC)
			printf("\n");
	}

	return 0;
}
