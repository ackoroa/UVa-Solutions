#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char board[8][8];
int attacked[8][8];

int main() {
	char fen[100];

	while (scanf("%s", fen) != EOF) {
		int len = strlen(fen), i = 0, j = 0;

		for (int k = 0; k < len; k++) {
			if (fen[k] == '/') {
				for (; j < 8; j++) {
					board[i][j] = '*';
				}
				i++;
				j = 0;
			} else if (isalpha(fen[k])) {
				board[i][j] = fen[k];
				j++;
			} else if (isdigit(fen[k])) {
				for (int l = 0; l < fen[k] - '0'; l++) {
					board[i][j] = '*';
					j++;
				}
			}
		}

		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				attacked[i][j] = 0;
			}
		}

		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				char piece = board[y][x];
				if(piece != '*') attacked[y][x]++;
				if (piece == 'p') {
					if (y + 1 < 8 && x + 1 < 8)
						attacked[y + 1][x + 1]++;
					if (y + 1 < 8 && x - 1 >= 0)
						attacked[y + 1][x - 1]++;
				}

				if (piece == 'P') {
					if (y - 1 >= 0 && x + 1 < 8)
						attacked[y - 1][x + 1]++;
					if (y - 1 >= 0 && x - 1 >= 0)
						attacked[y - 1][x - 1]++;
				}

				if (piece == 'k' || piece == 'K') {
					if (y + 1 < 8) {
						attacked[y + 1][x]++;
						if (x + 1 < 8)
							attacked[y + 1][x + 1]++;
						if (x - 1 >= 0)
							attacked[y + 1][x - 1]++;
					}
					if (x + 1 < 8)
						attacked[y][x + 1]++;
					if (x - 1 >= 0)
						attacked[y][x - 1]++;
					if (y - 1 >= 0) {
						if (x + 1 < 8)
							attacked[y - 1][x + 1]++;
						attacked[y - 1][x]++;
						if (x - 1 >= 0)
							attacked[y - 1][x - 1]++;
					}
				}

				if (piece == 'n' || piece == 'N') {
					if (y + 2 < 8 && x + 1 < 8)
						attacked[y + 2][x + 1]++;
					if (y + 2 < 8 && x - 1 >= 0)
						attacked[y + 2][x - 1]++;

					if (y + 1 < 8 && x + 2 < 8)
						attacked[y + 1][x + 2]++;
					if (y - 1 >= 0 && x + 2 < 8)
						attacked[y - 1][x + 2]++;

					if (y - 2 >= 0 && x + 1 < 8)
						attacked[y - 2][x + 1]++;
					if (y - 2 >= 0 && x - 1 >= 0)
						attacked[y - 2][x - 1]++;

					if (y + 1 < 8 && x - 2 >= 0)
						attacked[y + 1][x - 2]++;
					if (y - 1 >= 0 && x - 2 >= 0)
						attacked[y - 1][x - 2]++;
				}

				if (piece == 'r' || piece == 'R' || piece == 'q'
						|| piece == 'Q') {
					int i = x + 1;
					while (i < 8) {
						attacked[y][i]++;
						if (board[y][i] != '*')
							break;
						i++;
					}
					i = x - 1;
					while (i >= 0) {
						attacked[y][i]++;
						if (board[y][i] != '*')
							break;
						i--;
					}
					i = y + 1;
					while (i < 8) {
						attacked[i][x]++;
						if (board[i][x] != '*')
							break;
						i++;
					}
					i = y - 1;
					while (i >= 0) {
						attacked[i][x]++;
						if (board[i][x] != '*')
							break;
						i--;
					}
				}

				if (piece == 'b' || piece == 'B' || piece == 'q'
						|| piece == 'Q') {
					int i = y + 1, j = x + 1;
					while (i < 8 && j < 8) {
						attacked[i][j]++;
						if (board[i][j] != '*')
							break;
						i++;
						j++;
					}
					i = y - 1, j = x + 1;
					while (i >= 0 && j < 8) {
						attacked[i][j]++;
						if (board[i][j] != '*')
							break;
						i--;
						j++;
					}
					i = y - 1, j = x - 1;
					while (i >= 0 && j >= 0) {
						attacked[i][j]++;
						if (board[i][j] != '*')
							break;
						i--;
						j--;
					}
					i = y + 1, j = x - 1;
					while (i < 8 && j >= 0) {
						attacked[i][j]++;
						if (board[i][j] != '*')
							break;
						i++;
						j--;
					}
				}
			}
		}

		int ans= 0;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if(attacked[i][j] ==0) ans++;
				//printf("%c ", board[i][j]);
			}
			/*printf("\t");
			for (j = 0; j < 8; j++) {
				printf("%d ", attacked[i][j]);
			}
			printf("\n");*/
		}
		printf("%d\n",ans);
	}

	return 0;
}
