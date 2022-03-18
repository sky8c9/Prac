#include <iostream>

using namespace std;

void task() {
	int n;
	cin >> n;

	double ans = 0;
	for(int i = 0; i < n; i++) {
		double a;
		cin >> a;
		ans += 1/a;
	}

	printf("%.8f", 1/ans);
}

int main() {
	task();
	return 0;
}