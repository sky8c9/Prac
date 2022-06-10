#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> prev;
	for(int i = 1; i <= n; i++) {
		vector<int> cur(i);

		for(int j = 0; j < i; j++) {
			if (j == 0 || j == i - 1) {
				cout << 1 << " ";
				cur[j] = 1;
			} else {
				cur[j] = prev[j-1] + prev[j];
				cout << cur[j] << " ";
			}
		}

		prev = cur;
		cout << endl;
	}
}

int main() {
	task();
	return 0;
}