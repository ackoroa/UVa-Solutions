#include <cstdio>
using namespace std;

int main() {
	int k, S[12], count = 0;
	while (scanf("%d", &k), k) {
		if (count++)
			printf("\n");
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);

		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c],
										S[d], S[e], S[f]);
	}

	return 0;
}
