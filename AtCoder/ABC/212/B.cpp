#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;
	vector<int> x(4);
	bool t1 = true;
	bool t2 = true;

	for(int i = 0; i < s.length(); i++) x[i] = s[i] - '0';
	for(int i = 1; i < 4; i++) {
		if (x[i] != x[i-1]) t1 = false;
		if ((x[i-1] + 1) % 10 != x[i]) t2 = false;
	}

	if (t1 || t2) cout << "Weak" << endl;
	else cout << "Strong" << endl;
}

int main() {
	task();
	return 0;
}