#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& val : a) cin >> val;
    for(int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}