#include <iostream>

using namespace std;

void task() {
    int n,x;
    cin >> n >> x;

    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (val == x) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    task();
    return 0;
}