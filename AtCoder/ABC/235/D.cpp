#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
const int MAX = 1e6;
void task() {
	int a,N;
	cin >> a >> N;

	queue<long long> q;
	unordered_set<long long> seen;
	q.push(1);
	seen.insert(1);

	int step = 0;
	while(!q.empty()) {
		int size = q.size();

		while(size--) {
			long long cur = q.front(); q.pop();
			if (cur == N) {
				cout << step << endl;
				return;
			}

			if (cur * a < MAX && seen.count(cur * a) == 0) {
				q.push(cur * a);
				seen.insert(cur * a);
			}

			if (cur > 10 && cur % 10 != 0) {
				string s = to_string(cur);
      			long long val = stoll(s.back() + s.substr(0, s.size() - 1));

				if (val < MAX && seen.count(val) == 0) {
					q.push(val);
					seen.insert(val);
				}
			}
		}

		step++;
	}

	cout << -1 << endl;
}

int main() {
	task();
	return 0;
}