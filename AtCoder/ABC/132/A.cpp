#include <iostream>
#include <vector>
#include <string>
using namespace std;

void task() {
	string s;
	cin >> s;

	vector<char> seen(26, false);
	int cnt = 0;
	for(char c : s) {
		if (!seen[c - 'A']) {
			seen[c - 'A'] = true;
			cnt++;
		}
	}
	
	if (cnt == 2) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}