#include <iostream>
#include <vector>
#include <deque>

using namespace std;
void task() {
	int n,m;
	cin >> n >> m;

	vector<deque<int>> cylinders(m);
	vector<deque<int>> v2i(n+1);
	vector<int> counter(n+1);
	deque<int> q;

	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;

		while(k--) {
			int val;
			cin >> val;
			cylinders[i].push_back(val);
			v2i[val].push_back(i);
		}

		int frontVal = cylinders[i].front();
		if (++counter[frontVal] == 2) {
			q.push_back(frontVal);
		}
	}

	while(!q.empty()) {
		n--;
		int curVal = q.front(); q.pop_front();

		for(int index : v2i[curVal]) {
			cylinders[index].pop_front();
			if (cylinders[index].size() == 0) continue;

			int nextVal = cylinders[index].front();
			if (++counter[nextVal] == 2) {
				q.push_back(nextVal);
			}
		}	

	}

	if (n == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

}

int main() {
	task();
	return 0;
}