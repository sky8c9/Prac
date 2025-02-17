#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<bool> seen(n + 1);
    int cnt = n;
    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        seen[val] = true;
        --cnt;
    }

    cout << cnt << endl;
    for(int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    task();
    return 0;
}