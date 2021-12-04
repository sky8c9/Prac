#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;
	queue<int> q;
	priority_queue<int, vector<int>, greater<int>> pq;

	while(n--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x;
			q.push(x);
		} else if (t == 2) {
			if (pq.empty()) {
				cout << q.front() << endl;
				q.pop();
			} else {
				cout << pq.top() << endl;
				pq.pop();
			}
		} else if (t == 3) {
			while(!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}
	}
}

int main() {
	task();
	return 0;
}