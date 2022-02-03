#include <iostream>
#include <string>

using namespace std;

void task() {
	string x;
	cin >> x;

	string ans;
	int i = 0;
	while(i < x.length() && x[i] != '.') {
		ans += x[i++];
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}