#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void task() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> prefS(s.size());
    for(int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            prefS[i] = prefS[i - 1] + 1;
        } else prefS[i] = prefS[i - 1];
    }


    while(q--) {
        int l, r;
        cin >> l >> r;

        --l; --r;
        cout << (prefS[r] - prefS[l]) << endl;
    }
}

int main() {
    task();
    return 0;
}