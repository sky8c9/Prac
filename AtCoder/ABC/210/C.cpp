#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void task() {
	int n, k;
	int ans = 0;
	cin >> n >> k;

	unordered_map<int, int> freq;
	vector<int> c(n);

	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0, j = 0; j < n; j++) {
		freq[c[j]]++;

		while(j - i >= k) {
			freq[c[i]]--;
			if (freq[c[i]] == 0) freq.erase(c[i]);
			i++;
		}
		
		ans = max(ans, (int) freq.size());
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}