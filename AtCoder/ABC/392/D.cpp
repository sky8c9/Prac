#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<unordered_map<int, int>> v;
    vector<int> sz;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sz.push_back(k);

        unordered_map<int, int> vk;
        for(int i = 0; i < k; i++) {
            int val;
            cin >> val;
            ++vk[val];
        }

        v.push_back(vk);
    }

    double ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double cur = 0;
    
            for(auto[vali, freqi] : v[i]) {
                if (v[j].count(vali)) {
                    int freqj = v[j][vali];
                    cur += (freqi * 1.0 / sz[i]) * (freqj * 1.0 / sz[j]);
                }
            }

            ans = max(ans, cur);
        }
    }

    printf("%.10f\n", ans);
}

int main() {
    task();
    return 0;
}