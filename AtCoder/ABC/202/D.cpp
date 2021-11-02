#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
	int a,b;
	long long k;
	string ans;
	cin >> a >> b >> k;

	vector<vector<long long>> combi(61, vector<long long>(61));
	for(int i = 0; i < 61; i++) {
		combi[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
		}
	}

	while(a+b > 0) {
		long long val = a > 0 ? combi[a+b-1][a-1] : 0;
		if (val < k) {
			ans += 'b';
			k -= val;
			b--;
		} else {
			ans += 'a';
			a--;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}
