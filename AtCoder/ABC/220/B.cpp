#include <iostream>
#include <string>

using namespace std;

long long toDecimal(string in, int base) {
	long long ans = 0;

	for(char c : in) {
		ans = ans * base + (c - '0');
	}

	return ans;
}

void task() {
	int k;
	string a,b;
	cin >> k >> a >> b;

	long long ans = toDecimal(a,k) * toDecimal(b,k);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}