#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int n,k,m;
	cin >> n >> k >> m;

	int sum = 0;
	for(int i = 0; i < n - 1; i++) {
		int val;
		cin >> val;

		sum += val;
	}

	int need = m * n - sum;
	if (need <= k) cout << max(0, need) << endl;
	else cout << -1 << endl; 
}

int main() {
	task();
	return 0;
}