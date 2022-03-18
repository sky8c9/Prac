#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	vector<double> v(n);
	for(double& val : v) cin >> val;

	sort(v.begin(), v.end());
	double ans = v[0];
	for(int i = 1; i < n; i++) {
		ans = (ans + v[i]) / 2;
	}

	printf("%.8f\n", ans);
}

int main() {
	task();
	return 0;
}