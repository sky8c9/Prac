#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    int m = 0;
    while(1 << m < n) ++m;

    cout << m << endl;
    for(int i = 0; i < m; i++) {
        vector<int> a;
        for(int j = 0; j < n; j++) {
            if((j >> i) & 1) {
                a.push_back(j + 1);
            }
        }

        cout << a.size();
        for(int val : a) {
            cout << " " << val;
        }

        cout << endl;
    }

    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ans += 1 << i;
        }
    }

    cout << (ans + 1) << endl;
}

int main() {
    task();
    return 0;
}