#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

void task() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> freq(10, 0);
    for(int i = 0; i < n; i++) ++freq[s[i] - '0'];

    int ans = 0;
    ll MAX = pow(10, n);
    for(ll i = 0; i * i < MAX; i++) {
        ll num = i * i;
        vector<int> cnt(10, 0);
        while(num) {
            ++cnt[num % 10];
            num /= 10;
        }

        bool flag = true;
        for(int j = 1 ; j < 10; j++) {
            if (cnt[j] != freq[j]) {
                flag = false;
                break;
            }
        }

        if (flag) ++ans;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}