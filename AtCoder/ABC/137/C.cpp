#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	vector<string> words(n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());

		words[i] = s;
	}

	unordered_map<string, ll> freq;
	for(string word : words) {
		freq[word]++;
	}

	ll ans = 0;
	for(auto[w,cnt] : freq) {
		ans += cnt * (cnt - 1) / 2;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}