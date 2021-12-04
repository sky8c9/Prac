#include <iostream>
#include <vector>

using namespace std;
void task() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);

	for(int&val : p) cin >> val;
	for(int i = 0; i < n; i++) {
		q[p[i] - 1] = i + 1;
	}

	for(int i = 0; i < n; i++) {
		cout << q[i] << " ";
	}
}

int main() {
	task();
	return 0;
}