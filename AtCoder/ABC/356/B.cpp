#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for(int&val : a) cin >> val;

    vector<int> total(m);
    while(n--) {
        for(int i = 0; i < m; i++) {
            int val;
            cin >> val;
            total[i] += val;
        }
    }

    for(int i = 0; i < m; i++) {
        if (total[i] < a[i]) {
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