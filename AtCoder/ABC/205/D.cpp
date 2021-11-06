#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n,q;

	cin >> n >> q;
	vector<long long> num(n);
	vector<long long> count(n);

	for(auto& val : num) {
		cin >> val;
	}

	for(int i = 0; i < num.size(); i++) {
		count[i] = num[i] - i - 1;
	}

	while(q--) {
		long long val;
		cin >> val;

		int index = lower_bound(count.begin(), count.end(), val) - count.begin();
		if (index == 0) cout << val << endl;
		else {
			val -= count[index - 1];
			cout << num[index - 1] + val << endl;
		}
	}
}

int main() {
	task();
	return 0;
}