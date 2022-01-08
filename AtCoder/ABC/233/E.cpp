#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	string X;
	cin >> X;

	vector<long long> a(X.length());
	ll sum = 0;
	for(int i = 0; i < X.length(); i++) {
		int digit = X[i] - '0';
		sum += digit;
		a[i] = sum;
	}

	string ans;
	ll carry = 0;
	for(int i = a.size() - 1; i >= 0; i--) {
		ll total = a[i] + carry;
		ans.push_back('0' + (total % 10));
		carry = total / 10;
	}

	while (carry) {
		ans.push_back('0' + (carry % 10));
		carry /= 10;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}