#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265359;

void task() {
	double a,b;
	cin >> a >> b;

	double angle = atan(b / a);
	double ansY = sin(angle);
	double ansX = cos(angle);

	printf("%.6f %.6f\n", ansX, ansY);
}

int main() {
	task();
	return 0;
}