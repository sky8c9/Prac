#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> ab;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        sum += b;
        ab.emplace_back(a, b);
    }

    sort(ab.begin(), ab.end());
    if (k >= sum) {
        cout << 1 << endl;
        return;
    }

    for(auto[day, val] : ab) {
        sum -= val;
        if (sum <= k) {
            cout << day + 1 << endl;
            return;
        }
    }
}

int main() {
    task();
    return 0;
}