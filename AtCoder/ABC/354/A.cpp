#include <iostream>

using namespace std;

void task() {
    int h;
    cin >> h;

    int curH = 0;
    int pow2 = 1;
    int ans = 0;
    while(curH <= h) {
        curH += pow2;
        pow2 <<= 1;
        ++ans;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}