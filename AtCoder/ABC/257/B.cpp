#include <iostream>
#include <vector>
using namespace std;

void task() {
	int n,k,q;
	cin >> n >> k >> q;

	vector<int> a(k);
	for(int i = 0; i < k; i++) cin >> a[i];
	for(int i = 0; i < q; i++) {
		int l;
		cin >> l;
		--l;

		if (a[l] == n) continue;
		if (l != k - 1 && a[l] + 1 == a[l + 1]) continue;
		a[l]++;
	}

	for(int i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
	
}

int main() {
	task();
	return 0;
}