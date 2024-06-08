#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> tries(m);
    vector<char> labels(m);
    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;

        int keys = 0;
        while(c--) {
            int key;
            cin >> key;
            --key;

            keys |= (1 << key);
        }

        tries[i] = keys;
        cin >> labels[i];
    }

    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        bool check = true;

        for(int j = 0; j < m; j++) {
            int cnt = 0;

            for(int key = 0; key < n; key++) {
                if (i >> key & 1) {
                    if (tries[j] >> key & 1) ++cnt;
                }
            }

            char c = cnt >= k ? 'o' : 'x';
            if (c != labels[j]) {
                check = false;
                break;
            }
        }

        if (check) ++ans;    
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}