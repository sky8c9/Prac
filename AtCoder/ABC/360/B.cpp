#include <iostream>
#include <string>

using namespace std;

void task() {
    string s, t;
    cin >> s >> t;

    for(int w = 1; w < s.size(); w++) {
        for(int c = 0; c < w; c++) {
            string combined = "";

            for(int i = 0; i < (s.size() + w - 1) / w; i++) {
                if (c + i * w >= s.size()) break;
                combined += s[c + i * w];
            }

            if (combined == t) {
                cout << "Yes" << endl;
                return;
            }
        }  
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}