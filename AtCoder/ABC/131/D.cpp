#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	map<ll, ll> m;
	for(int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		m[b] += a;
	}

	ll sum = 0;
	for(auto[deadline,work] : m) {
		sum += work;
		
		if (sum > deadline) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}