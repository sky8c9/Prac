#include <iostream>
#include <deque>

using namespace std;

void task() {
	int n;
	cin >> n;

	deque<pair<int,int>> dq;
	int size = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (dq.empty() || dq.back().first != a) {
			dq.push_back(make_pair(a,1));
		} else {
			if (dq.back().second + 1 == a) {
				size -= a;
				dq.pop_back();
			} else {
				dq.back().second++;
			}
		}

		size++;
		cout << size << endl;
	}
}

int main() {
	task();
	return 0;
}