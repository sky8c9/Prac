#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	vector<int> in(3);
	cin >> in[0] >> in[1] >> in[2];
	sort(in.begin(), in.end());

	if (in[2] - in[1] == in[1] - in[0]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	task();
	return 0;
}