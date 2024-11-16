#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double dist(int a, int b, int c, int d, int scale) {
    double dx = a - c;
    double dy = b - d;
    return sqrt(dx * dx  + dy * dy) / scale;
}

void task() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<vector<int>> p;
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        p.push_back({a, b, c, d});
    }

    double ans = 1e9;
    vector<int> idx(n);
    for(int i = 0; i < n; i++) idx[i] = i;
    do {
        for(int i = 0; i < 1 << n; i++) {
            double cost = 0;
            int curX = 0;
            int curY = 0;

            for(int j = 0; j < n; j++) {
                int pos = idx[j];
                cost += dist(p[pos][0], p[pos][1], p[pos][2], p[pos][3], t);

                if (i >> j & 1) {
                    cost += dist(curX, curY, p[pos][0], p[pos][1], s);
                    curX = p[pos][2];
                    curY = p[pos][3];
                } else {
                    cost += dist(curX, curY, p[pos][2], p[pos][3], s);
                    curX = p[pos][0];
                    curY = p[pos][1];
                }
            }

            ans = min(ans, cost);
        }
    } while(next_permutation(idx.begin(), idx.end()));

    printf("%.8f\n", ans);
}

int main() {
    task();
    return 0;
}