#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a;
    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        a.emplace_back(i, val);
    }

    vector<int> scores(n);
    map<int, set<int>> seen;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        scores[i] = i;
        for(int j = 0; j < m; j++) {
            if (s[j] == 'o') {
                scores[i] += a[j].second;
                seen[i].insert(j);
            }
        }
        
        mx = max(mx, scores[i]);
    }

    sort(a.begin(), a.end(), [&](pair<int, int> p1, pair <int, int> p2) {
        return p1.second > p2.second;
    });

    for(int i = 0; i < n; i++) {
        if (scores[i] == mx) {
            cout << 0 << endl;
            continue;
        }

        int cur = scores[i];
        int ans = 0;
        for(int j = 0; j < m; j++) {
            if (seen[i].count(a[j].first)) continue;
            cur += a[j].second;
            ++ans;
            if (cur > mx) break;
        }

        cout << ans << endl;
    }

}

int main() {
    task();
    return 0;
}