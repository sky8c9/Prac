#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 1e9;

void task() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        p.emplace_back(val, i);
    }

    sort(p.begin(), p.end());

    int ans = MAX;
    set<int> indices;
    for(int i = 0, j = 0; j < n; j++) {
        indices.insert(p[j].second);
        
        if (indices.size() > k) {
            indices.erase(p[i].second);
            ++i;
        }

        if (indices.size() == k) {
            ans = min(ans, *indices.rbegin() - *indices.begin());
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}