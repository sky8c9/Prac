#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;
using T = tuple<vector<int>, vector<int>, vector<int>>;

void task() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(l);
    for(int& val : a) cin >> val;
    for(int& val : b) cin >> val;
    for(int& val : c) cin >> val;

    map<T, bool> dp;
    auto game  = [&] (auto game, T cur) -> bool {       
        auto [aa, bb, cc] = cur;
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        sort(cc.begin(), cc.end());
        cur = T(aa, bb, cc);

        if (dp.count(cur)) return dp[cur];

        bool res = false;
        vector<int> pa = aa;
        vector<int> pc = cc;
        for(int i = 0; i < pa.size(); i++) {
            aa.erase(aa.begin() + i);
            cc.push_back(pa[i]);
            
            res |= !game(game, T(bb, aa, cc));
            if (res) return dp[cur] = true;
            for (int j = 0; j < cc.size() - 1; j++) {
                if (pa[i] > cc[j]) {
                    aa.push_back(cc[j]);
                    vector<int> nc = cc;
                    nc.erase(nc.begin() + j);

                    res |= !game(game, T(bb, aa, nc));
                    if (res) return dp[cur] = true;
                    aa.pop_back();
                }
            }

            aa = pa;
            cc = pc;
        }

        return dp[cur] = res;
    };

    bool ans = game(game, T(a, b, c));
    if (ans) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}

int main() {
    task();
    return 0;
}