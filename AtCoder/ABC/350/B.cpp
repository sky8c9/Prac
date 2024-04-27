#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, q;
    cin >> n >> q;

    vector<bool> ans(n, true);
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        --t;

        ans[t] = !ans[t];
    }

    int cnt = 0;
    for(bool val : ans) {
        if (val) ++cnt;
    }

    cout << cnt << endl;
}

int main() {
    task();
    return 0;
}