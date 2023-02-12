#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
struct Bit {
    vector<ll> bit;
    ll size;
 
    Bit(ll n) {
        size = n + 1;
        bit.resize(size);
    }
 
    void update(ll i, ll val) {
        ++i;
        while(i <= size) {
            bit[i] += val;
            i += i & -i;
        }
    }
 
    ll sum(ll i) {
        ll sum = 0;
        ++i;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
 
        return sum;
    }
 
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
 
void task() {
    int n;
    string s;
    int q;
    cin >> n >> s >> q;
 
    vector<Bit> bits;
    vector<int> freq(26);
    Bit sequence(n);
    for(int i = 0; i < 26; i++) {
        Bit bit(n);
        bits.push_back(bit);
    }
 
    for(int i = 0; i < n; i++) {
        if (i && s[i] < s[i - 1]) sequence.update(i - 1, 1);
        char idx = s[i] - 'a';
        bits[idx].update(i, 1);
        ++freq[idx];
    }

    while(q--) {
        int t;
        cin >> t; 
 
        if (t == 1) {
            int x;
            char c;
            cin >> x >> c;
 
            --x;
            bits[s[x] - 'a'].update(x, -1);
            bits[c - 'a'].update(x, 1);
            
            --freq[s[x] - 'a'];
            ++freq[c - 'a'];

            if (x && s[x] < s[x - 1]) sequence.update(x - 1, -1);
            if (x < n - 1 && s[x] > s[x + 1]) sequence.update(x, -1);

            s[x] = c;

            if (x && s[x] < s[x - 1]) sequence.update(x - 1, 1);
            if (x < n - 1 && s[x] > s[x + 1]) sequence.update(x, 1);
        } else {
            int l, r;
            cin >> l >> r;
 
            --l; --r;
            bool flag = sequence.sum(l, r - 1) == 0;
            for(char c = s[l] + 1; c < s[r]; c++) {
                if (freq[c - 'a'] != bits[c - 'a'].sum(l, r)) flag = false;
            }
       
            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
 
int main() {
    task();
    return 0;
}