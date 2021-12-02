#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void task() {
	unordered_set<string> seen;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string first;
		string last;
		cin >> first >> last;

		string full = first + " " + last;
		if (seen.count(full)) {
			cout << "Yes" << endl;
			return;
		}

		seen.insert(full);
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}