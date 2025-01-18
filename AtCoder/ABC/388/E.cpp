#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    int lo = 0;
    int hi = n / 2;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2 + 1;
        bool checked = true;
        for(int i = 0; i < mid; i++) {
            if (2*a[i] > a[n - mid + i]) {
                checked = false;
                break;
            }
        }

        if (checked) lo = mid;
        else hi = mid - 1;
    }
   
    cout << lo << endl;
}

int main() {
    task();
    return 0;
}