#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void task() {
    vector<int> v(5);
    for(int& val : v) cin >> val;

    int difS = 0;
    for(int i = 0; i < 5; i++) {
        difS += abs(v[i] - (i + 1));
    }

    if (difS == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}