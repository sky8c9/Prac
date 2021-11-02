#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void task() {
	int n;
	long long ans = 0;
	cin >> n;

	vector<int> b(n);
	unordered_map<int,int> seen;

	for(int i = 0; i < n ; i++) {
		int val;
		cin >> val;
		seen[val]++;
	}

	for(int i = 0; i < n ; i++) {
		int val;
		cin >> val;
		b[i] = val;
	}

	for(int i = 0; i < n ; i++) {
		int val;
		cin >> val;
		if (seen[b[val - 1]]) ans+= seen[b[val - 1]];
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}