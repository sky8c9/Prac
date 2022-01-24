#include <iostream>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	if (m < n) cout << "No" << endl;
	else cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}