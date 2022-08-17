#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int r,c;
	cin >> r >> c;
	if (max(abs(r - 8), abs(c - 8)) & 1) cout << "black" << endl;
	else cout << "white" << endl;
}

int main() {
	task();
	return 0;
}