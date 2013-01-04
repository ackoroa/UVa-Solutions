#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

bool comparator(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}

int main() {
	char word[1000];
	int n;

	cin >> n;
	while(n--){
		cin.ignore();
		cin >> word;

		sort(word,word+strlen(word),comparator);
		cout << word << endl;
		while(next_permutation(word,word+strlen(word),comparator)){
			cout << word << endl;
		}

	}

	return 0;
}
