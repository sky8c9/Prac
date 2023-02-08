#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void task() {
    string s;
    cin >> s;

    ll ans = 0;
    ll pow = 1;
    for(int i = 0; i < s.size(); i++) {
        ll d = s[s.size() - 1 - i] - 'A' + 1;
        ll added = pow * d;

        ans += added;
        pow *= 26;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}