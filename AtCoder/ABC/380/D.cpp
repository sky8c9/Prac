#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

void task() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    int len = s.size();
    while(q--) {
        ll k;
        cin >> k;
        --k;

        ll blk = k / len;
        int idx = k % len;

        bool flipped = false;
        for(int i = 0; i < 64; i++) {
            if (blk >> i & 1) flipped = !flipped;
        }

        char ans = s[idx];
        if (flipped) {
            if (isupper(ans)) ans = tolower(ans);
            else ans = toupper(ans);
        }
        
        cout << ans << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}