#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

const int MAX = 1e6;
void task() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> sum(n + 1, 0);
    vector<ll> ans(MAX, 0);
    for(int i = 0; i < n; i++) {
        int d = s[i] - '0';
        sum[i + 1] = sum[i] + (i + 1) * d;
        ans[n - i] += sum[i + 1] / 10;
        ans[n - i - 1] = sum[i + 1] % 10;    
    }

    int m = MAX - 1;
    for(int i = 0; i < m; i++) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10; 
    }

    while (ans[m] == 0) --m;
    while (m >= 0) {
        cout << char (ans[m] + '0');
        --m;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}