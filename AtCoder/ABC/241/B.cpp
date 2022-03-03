#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

void task() {
	int n,m;
	cin >> n >> m;

	unordered_map<ll,ll> freq;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		freq[a]++;
	}

	for(int i = 0; i < m; i++) {
		int b;
		cin >> b;

		if (freq[b] == 0) {
			cout << "No" << endl;
			return;
		}

		freq[b]--;
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}