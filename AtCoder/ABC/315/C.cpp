#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> fs;
    for(int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        fs.emplace_back(s, f);
    }

    sort(fs.rbegin(), fs.rend());
    
    int ans = 0;
    if (fs[0].second != fs[1].second) {
        ans = fs[0].first + fs[1].first;
    } else {
        ans = fs[0].first + fs[1].first / 2;
        for(int i = 2; i < n; i++) {
            if (fs[i].second != fs[0].second) {
                ans = max(ans, fs[i].first + fs[0].first);
                break;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}