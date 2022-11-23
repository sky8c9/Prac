#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n,k;
    cin >> n >> k;

    vector<int> ans(n);
    vector<int> a(n);
    for(int&val : a) cin >> val;
    if (k < n) {
        for(int i = k; i < n; i++) {
            ans[i - k] = a[i]; 
        }
    } 

    for(int val : ans) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}

