#include <iostream>
#include <map>
#include <vector>

using namespace std;

void task() {
	int n;
	long long k;
	cin >> n >> k;
	map<int,long long> ans;
	vector<int> a(n);

	long long q = k / n;
	long long r = k % n;
	for(int i = 0; i < n; i++) {
		int id;
		cin >> id;

		a[i] = id;
		ans[id] = q;
	}

	for(auto& [key,val] : ans) {
		if (r-- > 0) {
			val++;
		} else break;
	}

	for(int id : a) {
		cout << ans[id] << endl;
	}
}

int main() {
	task();
	return 0;
}