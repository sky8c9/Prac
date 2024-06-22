#include <iostream>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    while(n--) {
        int h;
        cin >> h;

        m -= h;
        if (m < 0) break;
        ++cnt;
    }

    cout << cnt << endl;
}

int main() {
    task();
    return 0;
}