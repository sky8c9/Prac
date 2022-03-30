#include <iostream>

using namespace std;

void task() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	if (a < c || (a == c && b <= d)) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
}

int main() {
	task();
	return 0;
}