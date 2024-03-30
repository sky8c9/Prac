#include <iostream>
#include <string>

using namespace std;

void task() {
    int w, b;
    cin >> w >> b;

    string s = "wbwbwwbwbwbw";
    for(int i = 0; i < s.size(); i++) {
        int cntW = 0;
        int cntB = 0;

        for(int j = 0; j < w + b; j++) {
            int idx = (i + j) % s.size();
            if (s[idx] == 'w') ++cntW;
            else ++cntB;
        }

        if (cntW == w && cntB == b) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}