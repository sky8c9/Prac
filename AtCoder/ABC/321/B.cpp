#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n - 1);
    for(int& val : a) cin >> val;
    for(int i = 0; i <= 100; i++) {
        vector<int> tmp = a;
        tmp.push_back(i);

        sort(tmp.begin(), tmp.end());
        
        int sum = 0;
        for(int j = 1; j < tmp.size() - 1; j++) {
            sum += tmp[j];
        }

        if (sum >= x) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}
