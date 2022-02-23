#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,k;
	cin >> n >> k;

	double ans = 0;
	for(int i = 1; i <= n; i++) {
		int tmp = i;
		double val = 1.0;

		while(tmp < k) {
			val/=2;
			tmp*=2;
		}

		ans += val;
	}

	printf("%.9f\n", ans / n);
}

int main() {
	task();
	return 0;
}