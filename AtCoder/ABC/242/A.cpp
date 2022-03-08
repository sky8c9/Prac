#include <iostream>
using namespace std;

void task() {
	int a,b,c,x;
	cin >> a >> b >> c >> x;

	double ans = 0;
	if (x <= a) ans = 1.0;
	else if (x <= b) ans = c * 1.0 / (b - a);

	printf("%.10f\n", ans);
}

int main() {
	task();
	return 0;
}