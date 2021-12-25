#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void task() {
	int n,q;
	cin >> n >> q;
	vector<pair<int,int>> states(n + 1);

	while(q--) {
		int type;
		cin >> type;

		if (type == 3) {
			int x;
			cin >> x;

			int cnt = 0;
			deque<int> dq;
			dq.push_back(x);

			int next = x;
			while(states[next].second) {
				cnt++;
				next = states[next].second;
				dq.push_back(next);
			}

			int prev = x;
			while(states[prev].first) {
				cnt++;
				prev = states[prev].first;
				dq.push_front(prev);
			}

			cout << cnt + 1;
			for(int val : dq) {
				cout << " " << val;
			}

			cout << endl;
		} else {
			int x,y;
			cin >> x >> y;

			if (type == 1) {
				states[x].second = y;
				states[y].first = x;
			} else {
				states[x].second = 0;
				states[y].first = 0;
			}
		}
	}
}

int main() {
	task();
	return 0;
}