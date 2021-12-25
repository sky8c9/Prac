#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> cnt(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int a,b;
		cin >> a >> b;

		cnt[a]++;
		cnt[b]++;
	}

	for(int i = 0; i <= n; i++) {
		if (cnt[i] == n - 1) {
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl; 
}

int main() {
	task();
	return 0;
}