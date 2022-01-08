#include <iostream>
#include <string>
using namespace std;

void task() {
	int l,r;
	string s;

	cin >> l >> r;
	l--;
	r--;
	cin >> s;

	for(int i = 0 ; i <= (r - l) / 2; i++) {
		swap(s[l+i], s[r-i]);
	}

	cout << s << endl;

}

int main() {
	task();
	return 0;
}