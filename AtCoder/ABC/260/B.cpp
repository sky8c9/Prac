#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) { 
	if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
} 

void task() {
	int n,x,y,z;
	cin >> n >> x >> y >> z;

	vector<bool> seen(n);
	vector<pair<int,int>> math;
	vector<pair<int,int>> engl;
	vector<pair<int,int>> sum;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		math.emplace_back(val, i + 1);
	}

	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		engl.emplace_back(val, i + 1);
	}

	for(int i = 0; i < n; i++) {
		sum.emplace_back(math[i].first + engl[i].first, i + 1);
	}

	vector<int> ans;
	sort(math.begin(), math.end(), compare);
	for(int i = 0; i < x; i++) {
		ans.push_back(math[i].second);
		seen[math[i].second] = true;
	}

	sort(engl.begin(), engl.end(), compare);
	for(int i = 0, j = 0; i < y; j++) {
		if (!seen[engl[j].second]) {
			ans.push_back(engl[j].second);
			seen[engl[j].second] = true;
			i++;
		}
	}

	sort(sum.begin(), sum.end(), compare);
	for(int i = 0, j = 0; i < z; j++) {
		if (!seen[sum[j].second]) {
			ans.push_back(sum[j].second);
			i++;
		}
	}

	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	task();
	return 0;
}