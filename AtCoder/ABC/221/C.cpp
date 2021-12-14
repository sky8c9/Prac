#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void task() {
	string s;
	cin >> s;

	int ans = 0;
	sort(s.begin(), s.end());

	do {
		for(int i = 1; i < s.length(); i++) {
			string a, b;

			for(int j = 0; j < i; j++) a += s[j];
			for(int j = i; j < s.length(); j++) b += s[j];

			ans = max(ans, stoi(a) * stoi(b));
		}
	} while(next_permutation(s.begin(), s.end()));

	cout <<  ans << endl;
}

int main() {
	task();
	return 0;
}