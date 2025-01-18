#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> p;
    while(n--) {
        int t, l;
        cin >> t >> l;
        p.emplace_back(t, l);
    }

    for(int i = 0; i <= d; i++) {
        vector<int> vals;
        for(auto[t, l] : p) vals.push_back(t * (l + i));
        sort(vals.rbegin(), vals.rend());
        if (i) cout << vals[0] << endl;
    }
}

int main() {
    task();
    return 0;
}