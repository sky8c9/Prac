#include <iostream>
#include <string>
using namespace std;

void task() {
	int n;
	string s,t;
	cin >> n >> s >> t;

	string ans;
	for(int i = 0; i < n; i++) {
		ans += s[i];
		ans += t[i];
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}