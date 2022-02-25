#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,k,q;
	cin >> n >> k >> q;
	vector<int> a(n + 1, k - q);
	for(int i = 0; i < q; i++) {
		int val;
		cin >> val;

		a[val]++;
	}

	for(int i = 1; i <= n; i++) {
		if (a[i] > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
} 

int main() {
	task();
	return 0;
}