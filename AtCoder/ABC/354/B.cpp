#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<pair<string, int>> sc;
    int total = 0;
    for(int i = 0; i < n; i++) {
        string s;
        int c;
        cin >> s >> c;

        sc.emplace_back(s, c);
        total += c;
    }

    sort(sc.begin(), sc.end());
    cout << sc[total % n].first << endl;
}

int main() {
    task();
    return 0;
}