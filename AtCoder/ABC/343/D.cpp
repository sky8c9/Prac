#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

void task() {
    int n, t;
    cin >> n >> t;

    vector<ll> scores(n, 0);
    map<ll, int> freq;
    freq[0] = n;
    while(t--) {
        int a, b;
        cin >> a >> b;
        --a;

        --freq[scores[a]];
        if (freq[scores[a]] == 0) freq.erase(scores[a]);
        
        scores[a] += b;
        ++freq[scores[a]];

        cout << freq.size() << endl;
    }
}

int main() {
    task();
    return 0;
}