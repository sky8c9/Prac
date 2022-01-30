#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.141592653589793;
void task() {
	int n;
	cin >> n;

	double x0,y0,x1,y1;
	cin >> x0 >> y0 >> x1 >> y1;

	double xmid = (x0 + x1) / 2;
	double ymid = (y0 + y1) / 2;

	double rad = 2*PI / n;
	double ansX = xmid + (x0 - xmid) * cos(rad) - (y0 - ymid) * sin(rad);
	double ansY = ymid + (x0 - xmid) * sin(rad) + (y0 - ymid) * cos(rad);

	printf("%.10f %.10f\n", ansX, ansY);
}

int main() {
	task();
	return 0;
}