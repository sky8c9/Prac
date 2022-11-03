#include <iostream>

using namespace std;
void task() {
    int n;
    cin >> n;
    int max = 0;
    int index = -1;
    for(int i = 1; i <= n; i++) {
        int h;
        cin >> h;

        if (h > max) {
            max = h;
            index = i;
        }
    }

    cout << index << endl;
}

int main() {
    task();
    return 0;
}