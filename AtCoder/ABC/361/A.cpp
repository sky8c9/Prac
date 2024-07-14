#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, k , x;
    cin >> n >> k >> x;

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (i == k) ans.push_back(x);
        ans.push_back(val);
    }

    if (k >= n) ans.push_back(x);
    for(int&val : ans) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}