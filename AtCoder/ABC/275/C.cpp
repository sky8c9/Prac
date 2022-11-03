#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void task() {
    vector<pair<int, int>> pawns;
    set<pair<int, int>> seen;
    for(int i = 0; i < 9; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < s.length(); j++) {
            if (s[j] == '#') {
                pawns.emplace_back(i, j);
                seen.emplace(i, j);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < pawns.size(); i++) {
        for(int j = 0; j < pawns.size(); j++) {
            if (i == j) continue;
            int di = pawns[j].first - pawns[i].first;
            int dj = pawns[j].second - pawns[i].second;

            pair<int, int> p3(pawns[j].first - dj, pawns[j].second + di);
            pair<int, int> p4(p3.first - di, p3.second - dj); 
            if (seen.count(p3) && seen.count(p4)) ++ans;
        }
    }

    ans /= 4;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}