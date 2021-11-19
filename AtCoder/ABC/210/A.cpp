#include <iostream>

using namespace std;

void task() {
	int n,a,x,y;
	cin >> n >> a >> x >> y;

	if (n > a) {
		cout << a * x + (n - a) * y << endl;
	} else {
		cout << n * x << endl;
	}
}

int main() {
	task();
	return 0;
}