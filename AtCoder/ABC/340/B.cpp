#include <iostream>
#include <vector>

using namespace std;

void task() {
    int q;
    cin >> q;

    vector<int> vals;
    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            vals.push_back(x);
        } else if (t == 2) {
            int k;
            cin >> k;
            cout << vals[vals.size() - k] << endl;
        }
    }
}

int main() {
    task();
}