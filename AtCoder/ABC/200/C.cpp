#include <iostream>
#include <vector>

using namespace std;

long long task() {
	int n;
	int val;
	vector<long long> a(200);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val;
		a[val % 200]++;
	}

	long long ans = 0;
	for(int i = 0; i < 200; i++) {
		ans += a[i] * (a[i] - 1) / 2;
	}

	return ans;
}

int main() {
	cout << task() << endl;
	return 0;
}