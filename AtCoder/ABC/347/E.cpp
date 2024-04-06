#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
void task() {
    int n, q;
    cin >> n >> q;

    vector<int> x(q);
    vector<ll> a(n + 1);
    for(int&val : x) cin >> val;

    ll sum = 0;
    set<int> seen; 
    for(int&val : x) {
        if (seen.count(val)) {
            seen.erase(val);
            a[val] += sum;
        } else {
            a[val] -= sum;
            seen.insert(val);
        }

        sum += seen.size();
    }

    for(int i = 1; i <= n; i++) {
        if (seen.count(i)) a[i] += sum;
    }

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}