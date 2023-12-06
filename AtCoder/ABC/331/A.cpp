#include <iostream>

using namespace std;

void task() {
    int M, D;
    cin >> M >> D;

    int y, m, d;
    cin >> y >> m >> d;

    if (++d > D) {
        ++m;
        d = 1;
    }

    if (m > M) {
        ++y;
        m = 1;
    }

    cout << y << " " << m << " " << d << endl;
}

int main() {
    task();
    return 0;
}