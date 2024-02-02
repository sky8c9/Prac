#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> rl;
    for(int i = 0; i < n; i++) {
        vector<int> ab(2);
        cin >> ab[0] >> ab[1];

        sort(ab.begin(), ab.end());
        rl.emplace_back(ab[1], ab[0]);
    }

    sort(rl.begin(), rl.end());
    for(int i = 0; i < n; i++) {
        auto[rr, ll] = rl[i];
        auto itr = lower_bound(rl.begin(), rl.end(), make_pair(ll, (int)1e9));
        if (itr->first > ll && itr->second < ll) {
            cout << "Yes" << endl;
            return;
        } else if (itr->second == ll) continue;
        else {
            itr->first = rr;
            itr->second = ll;
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}