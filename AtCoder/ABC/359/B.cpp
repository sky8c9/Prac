#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> prev(n + 1, -1);
    int ans = 0;
    for(int i = 0; i < 2*n; i++) {
        int a;
        cin >> a;

        if (prev[a] == -1) prev[a] = i;
        else if (i - prev[a] == 2) ++ans;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}