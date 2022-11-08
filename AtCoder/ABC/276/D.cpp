#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
    int n;
    cin >> n;

    int mn2 = 1e9;
    int mn3 = 1e9;
    int r = -1;
    vector<pair<int, int>> stat;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        int mul2 = 0;
        int mul3 = 0;
        while(a % 2 == 0) {
            a /= 2;
            ++mul2;
        }

        while(a % 3 == 0) {
            a /= 3;
            ++mul3;
        }

        if (r != -1 && a != r) {
            cout << -1 << endl;
            return;
        }

        r = a;
        mn2 = min(mn2, mul2);
        mn3 = min(mn3, mul3);
        stat.emplace_back(mul2, mul3);
    }

    int ans = 0;
    for(auto[cnt2,cnt3] : stat) {
        ans += cnt2 - mn2 + cnt3 - mn3;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}