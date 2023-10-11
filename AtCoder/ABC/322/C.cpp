#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for(int&val : a) cin >> val;
    for(int i = 1; i < n; i++) {
        auto itr = lower_bound(a.begin(), a.end(), i);
        cout << (*itr - i) << endl;
    }
    cout << 0 << endl;
}

int main() {
    task();
    return 0;
}