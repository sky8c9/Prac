#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

void task() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        for(int&val : a) cin >> val;
        for(int&val : b) cin >> val;

        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++) {
            p.emplace_back(a[i], b[i]);
        }

        sort(p.begin(), p.end());
        
        ll ans = MAX;
        ll sum = 0;
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < k - 1; i++) {
            pq.push(p[i].second);
            sum += p[i].second;
        }

        for(int i = k - 1; i < n; i++) {
            pq.push(p[i].second);
            sum += p[i].second;
            ans = min(ans, sum * p[i].first);

            if (pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}