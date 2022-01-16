#include <iostream>

using namespace std;

void task() {
	int w,h,x,y;
	cin >> w >> h >> x >> y;

	bool isCen = (x * 2 == w) && (y * 2 == h);
	double ans = (double) w * h / 2;
	printf("%.10f %d\n", ans, isCen);
}

int main() {
	task();
	return 0;
}