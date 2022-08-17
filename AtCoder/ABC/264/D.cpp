#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

void task() {
	string s;
	cin >> s;
	
	set<string> seen;
	queue<string> q;
	q.push(s);
	seen.insert(s);
	int len = 0;
	while(!q.empty()) {
		int sz = q.size();

		while(sz--) {
			string cur = q.front(); q.pop();
			if(cur == "atcoder") {
				cout << len << endl;
				return;
			}

			for(int i = 0; i < cur.length() - 1; i++) {
				swap(cur[i], cur[i+1]);

				if (seen.count(cur) == 0) {
					seen.insert(cur);
					q.push(cur);
				}

				swap(cur[i], cur[i+1]);
			}
		}

		++len;
	}
}

int main() {
	task();
	return 0;
}