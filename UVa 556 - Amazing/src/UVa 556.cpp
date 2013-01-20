#include <cstdio>
using namespace std;

int maze[100][100];
int x, y, dir;

void mov() {
	if (dir == 0) {
		if (maze[y - 1][x + 1] == -1 && maze[y - 1][x] != -1)
			y--;
		else if (maze[y - 1][x] != -1) {
			y--;
			dir = 3;
		} else {
			dir++;
			mov();
		}
	} else if (dir == 1) {
		if (maze[y - 1][x - 1] == -1 && maze[y][x - 1] != -1)
			x--;
		else if (maze[y][x - 1] != -1) {
			x--;
			dir--;
		} else {
			dir++;
			mov();
		}
	} else if (dir == 2) {
		if (maze[y + 1][x - 1] == -1 && maze[y + 1][x] != -1)
			y++;
		else if (maze[y + 1][x] != -1) {
			y++;
			dir--;
		} else {
			dir++;
			mov();
		}
	} else if (dir == 3) {
		if (maze[y - 1][x + 1] == -1 && maze[y][x + 1] != -1)
			x++;
		else if (maze[y][x + 1] != -1) {
			x++;
			dir--;
		} else {
			dir = 0;
			mov();
		}
	}
}

int main() {
	int b, w, i, j;

	while (scanf("%d %d", &b, &w), b || w) {
		for (i = 0; i <= w + 1; i++)
			maze[0][i] = -1;
		getc(stdin);
		for (i = 1; i < b + 1; i++) {
			maze[i][0] = -1;
			for (j = 1; j < w + 1; j++) {
				char c;
				scanf("%c", &c);
				if (c == '1')
					maze[i][j] = -1;
				else
					maze[i][j] = 0;
			}
			maze[i][w + 1] = -1;
			getc(stdin);
		}
		for (i = 0; i <= w + 1; i++)
			maze[b + 1][i] = -1;

		x = 1, y = b, dir = 3;

		do {
			mov();
			//printf("%d %d\n", x, y);
			maze[y][x]++;
		} while (!(x == 1 && y == b));

		int data[5] = { 0, 0, 0, 0, 0 };
		for (i = 1; i <= b; i++) {
			for (j = 1; j <= w; j++) {
				if (maze[i][j] < 5)
					data[maze[i][j]]++;
			}
		}

		for (i = 0; i < 5; i++) {
			printf("%3d", data[i]);
		}
		printf("\n");
/*
		for (i = 0; i <= b + 1; i++) {
			for (j = 0; j <= w + 1; j++) {
				printf("%3d", maze[i][j]);
			}
			printf("\n");
		}
*/
	}

	return 0;
}
