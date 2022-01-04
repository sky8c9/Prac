#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

void findMax(map<string, int>& M)
{
    vector<pair<string, int>> ans;
    for (auto& it : M) {
        ans.push_back(it);
    }

    sort(ans.begin(), ans.end(), cmp);  
    cout << ans.rbegin()->first << endl;
}

void task() {
	int n;
	cin >> n;

	map<string, int> count;
	while(n--) {
		string s;
		cin >> s;
		count[s]++;
	}

	findMax(count);
}

int main() {
	task();
	return 0;
}