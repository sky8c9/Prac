#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e6;

void task() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> cnt(MAX + 1);
    for(int& val : a) {
        cin >> val;
        ++cnt[val];
    }

    for(int i = 1; i <= MAX; i++) {
        for(int j = 2*i; j <= MAX; j+=i) cnt[i] += cnt[j];
    }

    vector<int> mx(MAX + 1, 1);
    for(int i = 1; i <= MAX; i++) {
        if (cnt[i] < k) continue;
        for(int j = i; j <= MAX; j+=i) mx[j] = i;
    }

    for(int i = 0; i < n; i++) {
        cout << mx[a[i]] << endl;
    }
}

int main() {
    task();
    return 0;
}