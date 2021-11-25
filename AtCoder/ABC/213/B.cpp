#include <iostream>

using namespace std;

void task() {
	int n;
	cin >> n;

	int fmax = -1;
	int findex = -1;
	int smax = -1;
	int sindex = -1;

	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		if (val > fmax) {
			smax = fmax;
			fmax = val;
			sindex = findex;
			findex = i;
		} else if (val > smax) {
			smax = val;
			sindex = i;
		}
	}

	cout << (sindex + 1) << endl;
}

int main() {
	task();
	return 0;
}