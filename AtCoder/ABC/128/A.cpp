#include <iostream>

using namespace std;

void task() {
	int a,p;
	cin >> a >> p;

	int totalP = 3 * a + p;
	int pies = totalP / 2;

	cout << pies << endl;
}

int main() {
	task();
	return 0;
}
