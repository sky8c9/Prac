#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first; 
}

void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cnt = 0;
        for(int j = 0; j < s.size(); j++) {
            if (s[j] == 'o') ++cnt;
        }
        p.emplace_back(cnt, i + 1);
    }

    sort(p.begin(), p.end(), cmp);
    for(int i = 0; i < n; i++) {
        cout << p[i].second << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}