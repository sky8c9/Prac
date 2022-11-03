#include <iostream>

using namespace std;
using ll = long long;

const int MOD = 998244353;
void task() {
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    ll ab = (a % MOD) * (b % MOD) % MOD;
    ll de = (d % MOD) * (e % MOD) % MOD;
    ll abc = (ab % MOD) * (c % MOD) % MOD;
    ll def = (de % MOD) * (f % MOD) % MOD;

    cout << (abc - def + MOD) % MOD << endl;
}

int main() {
    task();
    return 0;
}