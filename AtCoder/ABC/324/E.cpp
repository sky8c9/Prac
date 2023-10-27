#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    string t;
    cin >> n >> t;

    vector<int> pref(n, 0);
    vector<int> suff(n, 0);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cur1 = 0;
        int cur2 = 0;
        for(int j = 0; j < s.size(); j++) {
            if (cur1 < t.size() && s[j] == t[cur1]) ++cur1;
            if (cur2 < t.size() && s[s.size() - 1 - j] == t[t.size() - 1 - cur2]) ++cur2;
        }

        pref[i] = cur1;
        suff[i] = cur2; 
    }

    sort(suff.begin(), suff.end());

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        auto itr = lower_bound(suff.begin(), suff.end(), t.size() - pref[i]);
        if (itr == suff.end()) continue;
        ans += suff.size() - (itr - suff.begin());
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}