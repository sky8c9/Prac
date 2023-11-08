#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    for(int i = n; i <= 919; i++) {
        int cur = i;
        int one = cur % 10;
        cur /= 10;

        int ten = cur % 10;
        cur /= 10;

        if (cur * ten == one) {
            cout << i << endl;
            break;
        }
    }

    return;
}

int main() {
    task();
    return 0;
}