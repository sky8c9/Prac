#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    map<int, int> m;
    while(n--) {
        int a, c;
        cin >> a >> c;

        if (m.count(c)) {
            m[c] = min(m[c], a);
        } else m[c] = a;
    }

    int ans = 0;
    for(auto[k, v] : m) ans = max(ans, v);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}