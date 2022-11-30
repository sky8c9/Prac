#include <iostream>
#include <vector>

using namespace std;
void task() {
    int n,m;
    cin >> n >> m;

    vector<int> a(m);
    for(int& val : a) cin >> val;

    vector<int> loc_1(m);
    int cur = 1;
    for(int i = 0; i < m; i++) {
        loc_1[i] = cur;
        if (a[i] == cur) cur++;
        else if (a[i] + 1 == cur) cur--;
    }

    vector<int> col(n + 1);
    for(int i = 0; i <= n; i++) col[i] = i;
    for(int i = m-1; i >= 0; i--) swap(col[a[i]], col[1 + a[i]]);
    for(int i = 0; i < m; i++) {
        swap(col[a[i]], col[1 + a[i]]);
        cout << col[loc_1[i]] << endl;
    }
}

int main() {
    task();
    return 0;
}