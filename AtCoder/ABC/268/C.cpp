#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> freq(n);
	for(int&val : p) cin >> val;
	for(int i = 0; i < n; i++) {
		int dist = (i - (p[i] - 1) + n) % n;
		++freq[dist];
		++freq[(dist+1) % n];
		++freq[(dist+2) % n];
	}

	int ans = 0;
	for(int f : freq) ans = max(ans, f);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}