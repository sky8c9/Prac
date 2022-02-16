#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.1415926535;
double toDeg(double rad) {
	return rad * 180 / PI;
}

void task() {
	double a,b,x;
	cin >> a >> b >> x;

	double area = a * b;
	double waterS = x / a;
	double deg;
	if (waterS >= area / 2) {
		double opp = 2.0 * (area - waterS) / a;
		deg = toDeg(atan(opp / a));
	} else {
		double adj = 2.0 * waterS / b;
		deg = toDeg(atan(b / adj));
	}

	printf("%.6f\n", deg);
}

int main() {
	task();
	return 0;
}