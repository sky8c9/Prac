#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	string s;
	int k;
	cin >> s >> k;

	sort(s.begin(), s.end());

	while(--k) {
		next_permutation(s.begin(), s.end());
	}

	cout << s << endl;
}

int main() {
	task();
	return 0;
}