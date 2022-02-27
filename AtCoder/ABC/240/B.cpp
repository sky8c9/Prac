#include <iostream>
#include <unordered_set>
using namespace std;

void task() {
	int n;
	cin >> n;
	
	unordered_set<int> seen;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		seen.insert(a);
	}

	cout << seen.size() << endl;
}

int main() {
	task();
	return 0;
}