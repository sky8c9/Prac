#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        if (i > n) continue;
        for(int j = 0; j <= n; j++) {
            if (i + j > n) continue;
            for(int k = 0; k <= n; k++) {
                if (i + j + k > n) continue;
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
}

int main() {
    task();
    return 0;
}