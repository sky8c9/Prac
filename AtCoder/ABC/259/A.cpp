#include <iostream>

using namespace std;

void task() {
	int n,m,x,t,d;
	cin >> n >> m >> x >> t >> d;

	if (m < x) {
		cout << t - (x - m) * d << endl;
	} else {
		cout << t << endl;
	}
}

int main() {
	task();
	return 0;
}