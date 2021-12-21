#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void task() {
	string s;
	cin >> s;

	set<string> ans;
	ans.insert(s);

	int n = s.length();
	for(int i = n - 1; i > 0; i--) {
		ans.insert(s.substr(i, n-i) + s.substr(0, i));
	}

	cout << *ans.begin() << endl;
	cout << *ans.rbegin() << endl;
}

int main() {
	task();
	return 0;
}