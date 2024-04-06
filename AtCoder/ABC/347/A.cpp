#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    for(int& val : a) {
        if (val % k == 0) {
            cout << (val / k) << " ";
        }
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}