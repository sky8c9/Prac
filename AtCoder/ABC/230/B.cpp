#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	string t = "oxx";
	for(int i = 0; i < 4; i++) t += "oxx";
	if (t.find(s) == string::npos) cout << "No" << endl;
	else cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}
