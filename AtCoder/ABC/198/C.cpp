#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

void task() {
	ll r,x,y;
	cin >> r >> x >> y;

	double d = sqrt(x*x + y*y);
	if (d == r) cout << 1 << endl;
	else if (d < 2*r) cout << 2 << endl;
	else cout << ceil(d / r) << endl;
}

int main() {
	task();
	return 0;
}