#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++) {
            a[i][j] = s[j] == 'o';
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            bool check = true;

            for(int k = 0; k < m; k++) {
                if (a[i][k] == false && a[j][k] == false) {
                    check = false;
                    break;
                }
            }

            ans += check;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}