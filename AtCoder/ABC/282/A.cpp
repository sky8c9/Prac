#include <iostream>

using namespace std;

void task() {
    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        char c = 'A' + i;
        cout << c;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}