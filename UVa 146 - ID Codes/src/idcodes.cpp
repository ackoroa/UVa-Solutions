#include <cstdio>
#include <algorithm>
#include <cstring>

int main() {
	char code[51];
	while (true) {
		scanf("%s", code);
		if (strcmp(code, "#") == 0)
			break;
		if (std::next_permutation(code, code + strlen(code)))
			printf("%s\n", code);
		else
			printf("No Successor\n");
	}

	return 0;
}
