#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void task() {
    int h, w, x;
    cin >> h >> w >> x;

    int pi, pj;
    cin >> pi >> pj;
    --pi; --pj;

    vector<vector<ll>> s(h, vector<ll>(w, 0));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> didj{1,0,-1,0,1};
    vector<vector<bool>> seen(h, vector<bool>(w, false));

    auto cmp = [&](pair<int, int> a, pair<int, int> b) {return s[a.first][a.second] > s[b.first][b.second];};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
    seen[pi][pj] = true;
    pq.push({pi, pj});
    ll ans = 0;
    while(pq.size()) {
        auto[i, j] = pq.top(); pq.pop();
        if (ans == 0 || (ans * 1.0 / x) > s[i][j]) {
            ans += s[i][j];
            for(int k = 0; k < 4; k++) {
                int ni = i + didj[k];
                int nj = j + didj[k + 1];

                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (!seen[ni][nj]) {
                    pq.push({ni, nj});
                    seen[ni][nj] = true;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}