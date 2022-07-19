#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n,x,y;
	cin >> n >> x >> y;

	vector<ll> dpR(11);
	vector<ll> dpB(11);
	dpR[1] = dpB[1] = 0;
	dpR[2] = x * y;
	dpB[2] = y;
	for(int i = 3; i <= 10; i++) {
		dpB[i] = dpR[i - 1] + y * dpB[i - 1];
		dpR[i] = dpR[i - 1] + x * dpB[i];
	}

	cout << dpR[n] << endl;
}

int main() {
	task();
	return 0;
}