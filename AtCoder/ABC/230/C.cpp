#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	ll n,a,b;
	cin >> n >> a >> b;

	ll p,q,r,s;
	cin >> p >> q >> r >> s;

	for(ll i = p; i <= q; i++) {
		string ans(s-r+1, '.');

		for(ll j = r; j <= s; j++) {
			if (i - j == a - b || i + j == a + b) ans[j-r] = '#';
		}

		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}