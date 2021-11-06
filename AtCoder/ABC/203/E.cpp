#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	map<int,vector<int>> tmap;
	unordered_set<int> ans;

	for(int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		tmap[x].push_back(y);
	}

	ans.insert(n);
	for(auto const&[posX, posYs] : tmap) {
		vector<int> reachable;

		for(int posY : posYs) {
			if (ans.count(posY - 1) > 0 || ans.count(posY + 1) > 0) {
				reachable.push_back(posY);
			}
		}

		for(int posY : posYs) ans.erase(posY);
		for(int posY : reachable) ans.insert(posY);
	}

	cout << ans.size() << endl;
}

int main() {
	task();
	return 0;
}