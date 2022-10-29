#include <iostream>
#include <vector>
using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> ans(2*n + 2);
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        ans[2*i] = ans[a] + 1;
        ans[2*i + 1] = ans[a] + 1;
    }

    for(int i = 1; i <= 2*n + 1; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    task();
    return 0;
}