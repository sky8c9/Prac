#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void task() {
	ll n;
	cin >> n;

	string num = to_string(n);
	int ans = 0;

	for(int i = 1; i <= n; i++) {
		string valI = to_string(i);
		ll cand = stol(valI + valI);
		
		if (cand <= n) ans++;
		else break;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}