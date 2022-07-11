#include <iostream>
#include <string>

using namespace std;

void task() {
	int n, q;
	string s;
	cin >> n >> q >> s;

	for(int i = 0, first = 0; i < q; i++) {
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			first += n - x;
			first %= n;
		} else if (t == 2) {
			cout << s[(first + x - 1) % n] << endl;
		}
	}
}

int main() {
	task();
	return 0;
}