#include <iostream>
using namespace std;

void task(long& n, const long& k) {
	for(int i = 0; i < k; i++) {
		if (n % 200 == 0) n /= 200;
		else n = n * 1000 + 200;
	}
}

int main() {
	long n;
	long k;

	cin >> n >> k;
	task(n,k);
	cout << n << endl;

	return 0;
}