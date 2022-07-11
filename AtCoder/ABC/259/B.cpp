#include <iostream>
#include <cmath>

using namespace std;
double PI = 3.14159265359;
void task() {
	int x,y,d;
	cin >> x >> y >> d;

	double rad = PI * d / 180.0;
	double x1 = x * cos(rad) - y * sin(rad);
	double y1 = x * sin(rad) + y * cos(rad);

	printf("%.8f %.8f\n", x1, y1);
}

int main() {
	task();
	return 0;
}