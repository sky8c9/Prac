#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	string s;
	int k;
	cin >> s >> k;

	int ans = 0;
	int cnt = 0;
	for(int i = 0, j = 0; j < s.length(); j++) {
		if (s[j] == '.') cnt++;

		while(i < s.length() && cnt > k) {
			if (s[i] == '.') cnt--;
			i++;
		}

		ans = max(ans, j - i + 1);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}