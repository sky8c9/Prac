#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    vector<string> t(m);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];
    for(int i = 0; i <= n - m; i++) {
        for(int j = 0; j <= n - m; j++) {
            bool flag = true;

            for(int ii = 0; ii < m && flag; ii++) {
                for(int jj = 0; jj < m && flag; jj++) {
                    if (s[i + ii][j + jj] != t[ii][jj]) {
                        flag = false;
                    }
                }
            }

            if (flag) {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
}

int main() {
    task();
    return 0;
}