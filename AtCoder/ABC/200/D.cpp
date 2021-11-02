#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print(const vector<int>& in);
void task();

void task() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> ans(200);
	int m = min(n,8);
	for(int i = 1; i < 1 << m; i++) {
		vector<int> tmp;
		int sum = 0;

		for(int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				tmp.push_back(j + 1);
				sum = (sum + a[j]) % 200;

			}
		}

		if (!ans[sum].size()) {
			ans[sum] = tmp;
		} else {
			cout << "Yes" << endl;
			print(ans[sum]);
			print(tmp);
			return;
		}
	}

	cout << "No" << endl;
}

void print(const vector<int>& in) {
	cout << in.size();
	for(auto& item : in) {
		cout << " " << item;
	}
	cout << endl;
}

int main() {
	task();
}