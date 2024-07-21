#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void task() {
    int r, g, b;
    cin >> r >> g >> b;

    vector<pair<int, string>> colors;
    colors.emplace_back(r, "Red");
    colors.emplace_back(g, "Green");
    colors.emplace_back(b, "Blue");
    sort(colors.begin(), colors.end());

    string c;
    cin >> c;

    for(int i = 0; i < 3; i++) {
        if (colors[i].second != c) {
            cout <<colors[i].first << endl;
            return;
        }
    }
}

int main() {
    task();
    return 0;
}