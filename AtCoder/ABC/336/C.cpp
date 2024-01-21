#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    ll n;
    cin >> n;
    --n;

    if (n == 0) {
        cout << 0 << endl;
    } else {
        string ans = "";
        vector<char> val{'0', '2', '4', '6', '8'};
        while(n) {
            ans += val[n % 5];
            n /= 5;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}
