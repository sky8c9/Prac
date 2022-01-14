#include <iostream>
#include <queue>

using namespace std;

void task() {
	int n,k;
	cin >> n >> k;

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;

		pq.push(p);
		if (pq.size() > k) pq.pop();
		if (i >= k - 1) cout << pq.top() << endl;
	}
}

int main() {
	task();
	return 0;
}