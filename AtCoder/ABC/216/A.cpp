#include <iostream>

using namespace std;

void task() {
	int x, y;
	scanf("%d.%d", &x, &y);

	if(y >= 0 && y <= 2) cout << x << "-" << endl;
	else if (y <= 6) cout << x << endl;
	else cout << x << "+" << endl;
}

int main() {
	task();
	return 0;
}