#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void task() {
	unordered_set<string> seen;
	for(int i = 0; i < 4; i++) {
		string s;
		cin >> s;

		if (seen.count(s)) {
			cout << "No" << endl;
			return;
		}
		seen.insert(s);
	}

	cout << "Yes" << endl;
	
}

int main() {
	task();
	return 0;
}