#include <iostream>

using namespace std;

void task() {
	int s,t,x;
	cin >> s >> t >> x;

	if (s < t) {
		if (x >= s && x < t) cout << "Yes" << endl;
		else cout << "No" << endl;
	} else {
		if (x >= t && x < s) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}

int main() {
	task();
	return 0;
}