#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
void task() {
    int n;
    cin >> n;

    vector<int> ans(n);
    vector<int> a(n);
    map<int,int> sa;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sa[a[i]] = 0;
    }

    int cnt = 1;
    for(auto [key, val] : sa) {
        sa[key] = sa.size() - cnt;
        ++cnt;
    } 

    for(int key : a) {
        ++ans[sa[key]];
    }

    for(int val : ans) {
        cout << val << endl;
    }
}

int main() {
    task();
    return 0;
}