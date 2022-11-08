#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int&val : p) cin >> val;
    prev_permutation(p.begin(), p.end());
    for(int val : p) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}