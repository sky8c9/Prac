#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	long long k;
	cin >> n >> k;

	vector<int> a(n);
	for(int& val : a) cin >> val;

	long long ans = 0;
	long long sum = 0;
	for(int i = 0, j = 0; j < n; j++) {
		sum += a[j];
		while(sum >= k) {
			ans+=(n - j);
			sum -= a[i++];
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}