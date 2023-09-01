#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
    int h, w;
    cin >> h >> w;

    int ans = h * w;
    vector<vector<int>> rStat(h, vector<int>(26));
    vector<vector<int>> cStat(w, vector<int>(26));
    vector<string> v;
    for(int i = 0; i < h; i++) {
        string s;
        cin >> s;
        v.push_back(s);

        for(int j = 0; j < w; j++) {
            ++rStat[i][v[i][j] - 'a'];
            ++cStat[j][v[i][j] - 'a'];
        }
    }

    vector<bool> emptyR(h, false);
    vector<bool> emptyC(w, false);
    bool found = true;
    while(found) {
        vector<pair<int, int>> detectR;
        vector<pair<int, int>> detectC;
        for(int i = 0; i < h; i++) {
            if (emptyR[i]) continue;
            int cnt = 0;
            int rC = -1;
            for(int k = 0; k < 26; k++) {
                if (rStat[i][k]) {
                    ++cnt;
                    rC = k;
                }
            }

            if (cnt == 1 && rStat[i][rC] > 1) detectR.emplace_back(i, rC);
        }

        for(int j = 0; j < w; j++) {
            if (emptyC[j]) continue;
            int cnt = 0;
            int cC = -1;
            for(int k = 0; k < 26; k++) {
                if (cStat[j][k]) {
                    ++cnt;
                    cC = k;
                }
            }
            if (cnt == 1 && cStat[j][cC] > 1) detectC.emplace_back(j, cC);
        }

        if (detectR.size()) {
            for(int i = 0; i < detectR.size(); i++) {
                auto[rowi, k] = detectR[i];
                for(int j = 0; j < w; j++) {
                    if (emptyC[j]) continue;
                    if (cStat[j][k]) {
                        --cStat[j][k];
                        --ans;
                    }
                }
                emptyR[rowi] = true;
            }
        }

        if (detectC.size()) {
            for(int j = 0; j < detectC.size(); j++) {
                auto[colj, k] = detectC[j];
                for(int i = 0; i < h; i++) {
                    if (emptyR[i]) continue; 
                    if (rStat[i][k]) {
                        --rStat[i][k];
                        --ans;
                    }
                }
                emptyC[colj] = true;
            }
        }

        found = (detectR.size() || detectC.size());
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}