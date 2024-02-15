#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> m;
ll compute(ll n) {
    if (n < 2) return 0;
    if (n == 2) return 2;

    ll lower = m[n / 2] ? m[n / 2] : compute(n / 2);
    ll upper = m[(n + 1) / 2] ? m[(n + 1) / 2] : compute((n + 1) / 2);

    return m[n] = n + lower + upper;
}

void task() {
    ll n;
    cin >> n;
    cout << compute(n) << endl;
}

int main() {
    task();
}