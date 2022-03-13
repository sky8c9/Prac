#include <iostream>
#include <vector>
using namespace std;

void task() {
	int v,a,b,c;
	cin >> v >> a >> b >> c;

	int r = v % (a + b + c);
	if (r < a) cout << "F" << endl;
	else if (r - a < b) cout << "M" << endl;
	else cout << "T" << endl;
}

int main() {
	task();
	return 0;
}