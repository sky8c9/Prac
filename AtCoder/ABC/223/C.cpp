#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<double> t(n);

	double totalT = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		t[i] = a[i] * 1.0 / b[i];
		totalT += t[i];
	}

	double meetT = totalT / 2;
	double ans = 0;
	for(int i = 0; i < n; i++) {
		if (meetT >= t[i]) {
			ans += a[i];
			meetT -= t[i];
		} else {
			ans += meetT * b[i];
			cout << ans << endl;
			return;
		}
	}
}

int main() {
	task();
	return 0;
}