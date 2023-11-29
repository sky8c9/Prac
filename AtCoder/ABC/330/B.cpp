#include <iostream>
#include <cstdlib>

using namespace std;

void task() {
    int n, l, r;
    cin >> n >> l >> r;

    while(n--) {
        int val;
        cin >> val;
        
        if (val >= l && val <= r) cout << val << " ";
        else if (val < l) cout << l << " ";
        else cout << r << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}