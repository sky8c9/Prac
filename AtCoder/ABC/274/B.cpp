#include <iostream>
#include <string>
#include <vector>
using namespace std;

void task() {
    int h, w;
    cin >> h >> w;

    vector<int> ans(w, 0);
    for(int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < w; j++) {
            if (s[j] == '#') ++ans[j];
        }
    }

    for(int val : ans) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}