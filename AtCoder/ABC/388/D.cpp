#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> delta(n + 1);
    for(int&val : a) cin >> val;
    for(int i = 0; i < n; i++) {
        delta[i] += i ? delta[i - 1] : 0;
        int val = max(0, a[i] + delta[i]);
        
        delta[i + 1] += 1;
        delta[min(i + val + 1, n)] -= 1;

        cout << max(0, val - (n - 1 - i)) << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}