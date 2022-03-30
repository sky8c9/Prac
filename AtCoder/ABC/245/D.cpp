#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);
	vector<int> b(m + 1);
	vector<int> c(n + m + 1);
	for(int&val : a) cin >> val;
	for(int&val : c) cin >> val;
	for(int i = m; i >= 0; i--) {
		b[i] = c[i + n] / a[n];

		for(int j = n; j >= 0; j--) {
			c[i + j] -= b[i] * a[j];
		}
	}

	for(int i = 0; i <= m; i++) {
		cout << b[i] << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}