#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n,k;
	cin >> n >> k;

	vector<string> s(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int ans = 0;
	for(int i = 0; i < (1 << n); i++) {
		vector<int> freq(26);
		int cnt = 0;

		for(int j = 0; j < n; j++) {
			if (((i >> j) & 1) != 1) continue;

			for(char c : s[j]) {
				freq[c - 'a']++;
			} 
		}

		for(int num : freq) {
			if (num == k) ++cnt;
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;

}

int main() {
	task();
	return 0;
}