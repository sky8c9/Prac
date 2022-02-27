#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int a,b;
	cin >> a >> b;
	if (abs(a-b) == 1 || abs(a-b) == 9) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}