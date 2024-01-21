#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using vvi = vector<vector<int>>;

map<vvi, int> bfs(queue<vvi>& q, int h, int w) {
    map<vvi, int> m;
    m[q.front()] = 0;

    while(q.size()) {
        auto cur = q.front(); q.pop();
        int d = m[cur];
        if (d == 10) break;

        for(int di = 0; di < 2; di++) {
            for(int dj = 0; dj < 2; dj++) {
                auto temp = cur;
    
                for(int i = 0; i < h - 1; i++) {
                    for(int j = 0; j < w - 1; j++) {
                        int ni = h - 2 - i;
                        int nj = w - 2 - j;

                        if (i > ni) continue;
                        if (i == ni && j > nj) continue;
                        swap(temp[i + di][j + dj], temp[ni + di][nj + dj]);
                    }
                }

                if (m.count(temp)) continue;
                m[temp] = d + 1;
                q.push(temp);
            }
        }
    }

    return m;
}

void task() {
    int h, w;
    cin >> h >> w;

    vvi b(h, vector<int>(w, 0));
    vvi e = b;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> b[i][j];
            e[i][j] = i * w + j + 1;
        }
    }

    queue<vvi> qb;
    queue<vvi> qe;
    qb.push(b); qe.push(e);
    map<vvi, int> mb = bfs(qb, h, w);
    map<vvi, int> me = bfs(qe, h, w);

    int ans = 1e9;
    for(auto[v, d] : mb) {
        if (me.count(v)) {
            ans = min(ans, d + me[v]);
        }
    }

    ans = ans == 1e9 ? -1 : ans;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}