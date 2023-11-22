#include <iostream>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    int mx1 = 0;
    int mx2 = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a > mx1) {
            mx2 = max(mx2, mx1);
            mx1 = a;
        } else if (a > mx2 && mx1 != a) mx2 = a;
    }

    cout << mx2 << endl;
}

int main() {
    task();
    return 0;
}