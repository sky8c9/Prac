#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	cout << max(a,b) - min(c,d) << endl;
}

int main() {
	task();
	return 0;
}