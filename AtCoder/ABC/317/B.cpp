#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& val : a) cin >> val;
    sort(a.begin(), a.end());

    for(int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] != 1) {
            cout << a[i - 1] + 1 << endl;
            break;
        }
    }
}

int main() {
    task();
    return 0;
}