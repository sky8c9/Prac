#include <iostream>

using namespace std;

void task() {
	int y;
	cin >> y;

	while(y % 4 != 2) y++;
	cout << y << endl;
}

int main() {
	task();
	return 0;
}