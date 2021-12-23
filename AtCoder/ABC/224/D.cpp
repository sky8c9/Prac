#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

string toString(vector<int>& in) {
	string ans = "0";
	for(int val : in) ans += to_string(val);
	return ans;
}

bool isComplete(vector<int>& in) {
	for(int i = 1; i <= 8; i++) {
		if (in[i] != i) return false;
	}

	return true;
}

void task() {
	int m;
	cin >> m;

	vector<vector<int>> adjL(10);
	while(m--) {
		int u,v;
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	vector<int> p(10);
	for(int i = 1; i <= 8; i++) {
		int v;
		cin >> v;
		p[v] = i;
	}

	unordered_set<string> seen;
	queue<vector<int>> q;
	int d = 0;

	q.push(p);
	seen.insert(toString(p));
	while(!q.empty()) {
		int size = q.size();

		while(size--) {
			vector<int> pos = q.front(); q.pop();
			if(isComplete(pos)) {
				cout << d << endl;
				return;
			}

			for(int u = 1; u < 10; u++) {
				if (pos[u]) continue;
				for(int v : adjL[u]) {
					swap(pos[u], pos[v]);

					string sequence = toString(pos);
					if (seen.count(sequence) == 0) { 
						q.push(pos);
						seen.insert(sequence);
					}

					swap(pos[u], pos[v]);
				}
			}
		}

		++d;
	}

	cout << -1 << endl;
}

int main() {
	task();
	return 0;
}