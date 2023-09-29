#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    int prev = -1;
    while(n > 0) {
        int d = n % 10;
        
        if (d <= prev) {
            cout << "No" << endl;
            return;
        } 

        prev = d;
        n /= 10;
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}