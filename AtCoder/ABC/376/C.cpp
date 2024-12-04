#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& a, vector<int>& b, int val) {
    vector<int> tmp = b;
    tmp.push_back(val);
    sort(tmp.begin(), tmp.end());

    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if (a[i] > tmp[i]) ++cnt;
    }

    return cnt == 0;
}

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& val : a) cin >> val;

    vector<int> b(n - 1);
    for(int& val : b) cin >> val;

    sort(a.begin(), a.end());

    int lo = 0;
    int hi = n - 1;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(a, b, a[mid])) hi = mid;
        else lo = mid + 1;
    }

    if (check(a, b, a[lo])) cout << a[lo] << endl;
    else cout << -1 << endl;
}

int main() {
    task();
    return 0;
}