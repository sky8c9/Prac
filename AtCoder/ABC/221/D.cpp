#include <iostream>
#include <map>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	map<int, int> freq;
	vector<int> ans(n + 1);

	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		freq[a]++;
		freq[a+b]--;
	}

	int sum = 0;
	int prev = -1;

	for(auto&[k,v] : freq) {
		if (prev != -1) {
			ans[sum] += k - prev - 1;
		}

		sum += v;
		ans[sum] += 1;
		prev = k;
	}

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}

int main() {
	task();
	return 0;
}