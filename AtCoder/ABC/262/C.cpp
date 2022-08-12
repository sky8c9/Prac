#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	ll ans = 0;
	ll same = 0;
	vector<int> m(n + 1, -1);
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		if (i == a) same++;
		else {
			m[i] = a;
			if (m[a] == i) ans++;
		}
	}


	ans += same * (same - 1) / 2;
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}