#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int m;
    cin >> m;

    vector<int> d(m);
    for(int& val : d) cin >> val;

    vector<int> prefS(m + 1);
    for(int i = 0; i < m; i++) {
        prefS[i + 1] = d[i] + prefS[i];
    }

    int mid = (prefS[m] + 1) / 2;
    auto itr = lower_bound(prefS.begin(), prefS.end(), mid);
    int idx = itr - prefS.begin();

    cout << idx << " " << (mid - prefS[idx - 1]) << endl;
}

int main() {
    task();
    return 0;
}