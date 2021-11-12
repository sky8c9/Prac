#include <iostream>
#include <algorithm>

using namespace std;
void task() {
	int a,b,c;
	cin >> a >> b >> c;

	cout << max(max(a+b,a+c),b+c) << endl;
}

int main() {
	task();
	return 0;
}