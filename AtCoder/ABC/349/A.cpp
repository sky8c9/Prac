#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        sum += val;
    }

    cout << -sum << endl;
}

int main() {
    task();
    return 0;
}