#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

unordered_map<ll, ll> memo;
ll compute(ll val) {
    if (val == 0) return 1;
    if (val == 1) return 2;
    if (memo.count(val)) return memo[val];
    return memo[val] = compute(val / 3) + compute(val / 2);
}

void task() {
    ll n;
    cin >> n;
    cout << compute(n) << endl;  
}

int main() {
    task();
    return 0;
}