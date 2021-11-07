#include <iostream>
#include <cmath>

using namespace std;

void task() {
	int a,b,c;
	cin >> a >> b >> c;

	bool cEven = (c & 1) == 0;
	if (cEven) {
		a = abs(a);
		b = abs(b);
	}

	if (a == b) {
		cout << "=" << endl;
	} else if (a < b) {
		cout << "<" << endl;
	} else {
		cout << ">" << endl;
	}
}

int main() {
	task();
	return 0;
}