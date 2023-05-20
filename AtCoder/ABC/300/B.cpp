#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool doable(int s, int t, vector<string>& a, vector<string>& b) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            int ni = (i - s + a.size()) % a.size();
            int nj = (j - t + a[i].size()) % a[i].size();
           
            if (a[i][j] != b[ni][nj]) return false;
        }
    }

    return true;
}

void task() {
    int h,w;
    cin >> h >> w;

    vector<string> gridA(h);
    vector<string> gridB(h);
    for(int i = 0; i < h; i++) cin >> gridA[i];
    for(int i = 0; i < h; i++) cin >> gridB[i];

    for(int s = 0; s < h; s++) {
        for(int t = 0; t < w; t++) {
            if (doable(s, t, gridA, gridB)) {
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