#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void task() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> freq(n + 2, 0);
    for(int& val : a) {
        cin >> val;
        val = min(val, n + 1);
        ++freq[val];
    }

    set<int> cand;
    for(int i = 0; i <= n; i++) {
        if (freq[i]) continue;
        cand.insert(i);
    }

    while(q--) {
        int i, x;
        cin >> i >> x;
        --i;

        x = min(x, n + 1);
        --freq[a[i]];
        ++freq[x];

        if (freq[a[i]] == 0) cand.insert(a[i]);
        if (cand.count(x)) cand.erase(x);

        a[i] = x;
        cout << *cand.begin() << endl;

    }
}

int main() {
    task();
    return 0;
}