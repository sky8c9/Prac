#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    int t = 0;
    int a = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t += x;
        a += y;
    }

    if (t == a) cout << "Draw" << endl;
    else if (t > a) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl; 
}

int main() {
    task();
    return 0;
}