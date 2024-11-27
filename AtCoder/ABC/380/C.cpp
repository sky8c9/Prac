#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<pair<int, int>> p;
    for(int i = 0; i < s.size(); i++) {
        int start = i;

        while(i < s.size() && s[i] == '1') {
            ++i;
        }

        if (s[start] == '1') p.emplace_back(start, i);
    }

    int len = p[k - 1].second - p[k - 1].first;
    for(int i = 0; i < len; i++) {
        s[i + p[k - 2].second] = '1';
        s[i + p[k - 1].first]  = '0';
    }

    cout << s << endl;
}

int main() {
    task();
    return 0;
}