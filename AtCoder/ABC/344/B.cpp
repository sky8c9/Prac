#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    vector<int> v;
    int val;

    while(cin >> val) {
        v.push_back(val);
        if (val == 0) break;
    }

    reverse(v.begin(), v.end());
    for(int&val : v) cout << val << endl;
}

int main() {
    task();
    return 0;
}