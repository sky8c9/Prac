#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ca(n);
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[i] = val;
        ca[i] = val;
    }

    sort(a.begin(), a.end());
    vector<ll> prefS(n + 1);
    for(int i = 0; i < n; i++) {
        prefS[i + 1] = prefS[i] + a[i];
    }

    for(int i = 0; i < n; i++) {
        auto itr = upper_bound(a.begin(), a.end(), ca[i]);
        if (itr == a.end()) {
            cout << 0 << " ";
        } else {
            int idx = itr - a.begin(); 
            cout << prefS[n] - prefS[idx] << " ";
        }
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}