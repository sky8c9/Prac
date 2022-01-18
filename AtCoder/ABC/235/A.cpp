#include <iostream>

using namespace std;

void task() {
	int abc;
	cin >> abc;

	int d1 = abc % 10;
	abc /= 10;
	int d2 = abc % 10;
	abc /= 10;

	int ans = (d1*100 + d2*10 + abc) + (d2*100 + abc*10 + d1) + (abc*100 + d1*10 + d2);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}