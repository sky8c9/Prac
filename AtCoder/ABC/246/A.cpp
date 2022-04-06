#include <iostream>

using namespace std;

void task() {
	int x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int ansX = x1 ^ x2 ^ x3;
	int ansY = y1 ^ y2 ^ y3;

	cout << ansX << " " << ansY << endl;
}

int main() {
	task();
	return 0;
}