#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	long long sum = 0;
	cin >> n;

	vector<int> a(n);
	for(int& val : a) {
		cin >> val;
		sum += val;
	}

	long long x;
	cin >> x;

	long long q = x / sum;
	long long ans = q * n;
	sum *= q;
	for(int i = 0; i < n && sum <= x; i++) {
		sum += a[i];
		ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}