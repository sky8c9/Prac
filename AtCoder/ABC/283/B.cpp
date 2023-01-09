#include <iostream>
#include <vector>

using namespace std;
void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& val : a) cin >> val;
    
    int q;
    cin >> q;
    while(q--) {
        int t, k;
        cin >> t >> k;

        --k;
        if (t == 1) {
            int x;
            cin >> x;
            a[k] = x;
        } else {
            cout << a[k] << endl;
        }
    }
}

int main() {
    task();
    return 0;
}