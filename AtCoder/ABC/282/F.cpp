#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
     int n;
    cin >> n;

    int msb = 31 -  __builtin_clz(n);
    map<pair<int, int>, int> m;
    vector<pair<int, int>> pairs;
    for(int i = 0, index = 1; i <= msb; i++) {
        for(int j = 0; j + (1 << i) - 1 < n; j++) {
            int l = j + 1;
            int r = j + (1 << i);

            m[{j, i}] = index++;  
            pairs.emplace_back(l, r);
        }
    }

    cout << pairs.size() << endl;
    for(auto[l, r] : pairs) {
        cout << l << " " << r << endl;
    }
    
    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        --l;--r;

        int msb = 31 -  __builtin_clz(r - l + 1);
        int i1 = m[{l, msb}];
        int i2 = m[{r - (1 << msb) + 1, msb}];
        
        cout << i1 << " " << i2 << endl;
    }

    return 0;
}