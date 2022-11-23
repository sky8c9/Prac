#include <iostream>
#include <vector>

using namespace std;

void task() {
    int h,m;
    cin >> h >> m;

    while(true) {
        int h1 = h / 10;
        int h2 = h % 10;
        int m1 = m / 10;
        int m2 = h % 10;

        if (h1 * 10 + m1 <= 23 && h2 * 10 + m2 <= 59) break;
        ++m;
        h += m / 60;
        h %= 24;
        m %= 60;
    }

    cout << h << " " << m << endl;
}

int main() {
    task();
    return 0;
}

