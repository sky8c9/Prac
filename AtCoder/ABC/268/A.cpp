#include <iostream>
#include <set>

using namespace std;
void task() {
	set<int> seen;
	for(int i = 0; i < 5; i++) {
		int val;
		cin >> val;

		seen.insert(val);
	}

	cout << seen.size() << endl;
}

int main() {
	task();
	return 0;
}