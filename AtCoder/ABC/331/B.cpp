#include <iostream>
#include <algorithm>

using namespace std;

void task() {
    int n, s, m, l;
    cin >> n >> s >> m >> l;

    int ans = 1e9;
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 15; j++) {
            for(int k = 0; k <= 10; k++) {
                if (6 * i + 8 * j + 12 * k >= n) {
                    ans = min(ans, s * i + m * j + l * k);
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}