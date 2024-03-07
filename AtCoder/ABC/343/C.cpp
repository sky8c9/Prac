#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void task() {
    ll n;
    cin >> n;

    vector<ll> ans;
    for(int i = 1; (ll) i * i * i <= n; ++i) {
        ll val = (ll) i * i * i;
        string num = to_string(val);

        bool checked = true;
        for(int j = 0; j < num.size() / 2; j++) {
            if (num[j] != num[num.size() - 1 - j]) {
                checked = false;
                break;
            }
        }

        if (checked) ans.push_back(val);
    }

    cout << ans.back() << endl;
}

int main() {
    task();
    return 0;
}