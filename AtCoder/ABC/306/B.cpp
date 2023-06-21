#include <iostream>
#include <vector>

using namespace std;
using ll = unsigned long long;

void task() {
    ll ans = 0;
    ll pow = 1;
    for(int i = 0; i < 64; i++) {
        int val;
        cin >> val;

        if (val) {
            ans += pow;
        }            
        
        pow <<= 1; 
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}