#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 998244353;
void task() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<string, ll> m;
    m[""] = 1;
    for(int i = 0; i < n; i++) {
        map<string, ll> tmp;

        auto add = [&] (string cur, char c) -> void {
            string nxt = cur + c;
            string rnxt = nxt;
            reverse(rnxt.begin(), rnxt.end());

            bool isPalindrome = nxt == rnxt;
            if (nxt.size() != k) tmp[nxt] = 1;
            else if (!isPalindrome) {
                string t = nxt.substr(1);
                tmp[t] += m[cur];
                tmp[t] %= MOD;
            }
        };

        for(auto[w, v] : m) {
            if (s[i] == 'A' || s[i] == '?') add(w, 'A');
            if (s[i] == 'B' || s[i] == '?') add(w, 'B');
        }

        m = tmp;
    }

    ll ans = 0;
    for(auto[w, v] : m) {
        ans += v;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}