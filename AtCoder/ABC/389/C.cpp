#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
void task() {
    int q;
    cin >> q;

    vector<ll> val;
    val.push_back(0);

    int offset = 0;
    while(q--) {
        int t;
        cin >> t;

        if (t == 1 || t == 3) {
            if (t == 1) {
                int add;
                cin >> add;
                val.push_back(val.back() + add);
            } else {
                int k;
                cin >> k;
                --k;
                cout << val[k + offset] - val[offset] << endl;
            }
        } else {
            offset++;
        }
    }
}

int main() {
    task();
    return 0;
}