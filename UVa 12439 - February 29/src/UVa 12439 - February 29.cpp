#include <cstdio>
#include <cstring>
using namespace std;

int stm(char monthS[]) {
	if (strcmp(monthS, "January") == 0)
		return 1;
	if (strcmp(monthS, "February") == 0)
		return 2;
	if (strcmp(monthS, "March") == 0)
		return 3;
	if (strcmp(monthS, "April") == 0)
		return 4;
	if (strcmp(monthS, "May") == 0)
		return 5;
	if (strcmp(monthS, "June") == 0)
		return 6;
	if (strcmp(monthS, "July") == 0)
		return 7;
	if (strcmp(monthS, "August") == 0)
		return 8;
	if (strcmp(monthS, "September") == 0)
		return 9;
	if (strcmp(monthS, "October") == 0)
		return 10;
	if (strcmp(monthS, "November") == 0)
		return 11;
	if (strcmp(monthS, "December") == 0)
		return 12;
	return -1;
}

int main() {
	int tc, count = 1, ans;
	scanf("%d", &tc);

	int mS, dS, yS, mE, dE, yE;
	char mStr[20];

	while (tc-- > 0) {
		scanf("%s %d, %d", mStr, &dS, &yS);
		mS = stm(mStr);

		scanf("%s %d, %d", mStr, &dE, &yE);
		mE = stm(mStr);

		if (mS > 2)
			yS++;
		if (mE < 2 || (mE == 2 && dE < 29))
			yE--;

		ans = yE / 4 - (yS - 1) / 4;
		ans -= yE / 100 - (yS - 1) / 100;
		ans += yE / 400 - (yS - 1) / 400;

		printf("Case %d: %d\n", count++, ans);
	}

	return 0;
}
