#include <iostream>
#include <string>
#include <deque>
using namespace std;
using ll = long long;

void task() {
	ll n,x;
	cin >> n >> x;

	string s;
	cin >> s;
	deque<char> ansBin;
	while(x) {
		ansBin.push_front(x % 2 == 0 ? '0' : '1');
		x /= 2;
	}

	for(char c : s) {
		if (c == 'U' && ansBin.size() > 0) {
			ansBin.pop_back();
		} else if (c == 'L') {
			ansBin.push_back('0');
		} else {
			ansBin.push_back('1');
		}
	}

	ll ans = 0;
	ll val = 1;
	while(ansBin.size()) {
		if (ansBin.back() == '1') ans += val;
		ansBin.pop_back();
		val *= 2;
	}

	cout << ans << endl;

}

int main() {
	task();
	return 0;
}