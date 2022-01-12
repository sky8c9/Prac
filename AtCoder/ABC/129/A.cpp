#include <iostream>
#include <algorithm>
using namespace std;

void task() {
	int p,q,r;
	cin >> p >> q >> r;
	
	int ans = min(p+r, min(p+q,q+r));
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}