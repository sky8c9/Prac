#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void task() {
	int n,x;
	cin >> n >> x;

	vector<int> a(n + 1);
	unordered_set<int> seen;
	for(int i = 1; i <= n; i++) cin >> a[i];

	while(seen.count(x) == 0) {
		seen.insert(x);
		x = a[x];
	}

	cout << seen.size() << endl;
}

int main() {
	task();
	return 0;
}