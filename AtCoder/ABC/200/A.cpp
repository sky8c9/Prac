#include <iostream>

using namespace std;

int century(int n) {
	return (n + 100 - 1) / 100;
}

int main() {
	int n;
	cin >> n;
	cout << century(n) << endl;

	return 0;
}