#include <iostream>
#include <vector>

using namespace std;
void task() {
	int n,k;
	cin >> n >> k;

	int maxK = (n-1) * (n-2) / 2;
	if (k > maxK) {
		cout << -1 << endl;
		return;
	}

	vector<pair<int,int>> ans;
	vector<pair<int,int>> edges;
	for(int i = 1; i < n - 1; i++) {
		for(int j = 0; j < i; j++) {
			edges.emplace_back(i,j);
		}
	}
	for(int i = 0; i < n-1; i++) {
		ans.emplace_back(i,n-1);
	}

	int diff = maxK - k;
	for(int i = 0; i < diff; i++) {
		ans.emplace_back(edges[i]);
	}

	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
}

int main() {
	task();
	return 0;
}