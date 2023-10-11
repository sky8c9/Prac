#include <iostream>
#include <string>
#include <vector>

#define R 4
#define C 4
#define P 3

using namespace std;

void rotate(vector<string>& m) {
    for(int i = 0; i < R; i++) {
        for(int j = i; j < C; j++) {
            swap(m[i][j], m[j][i]);
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C / 2; j++) {
            swap(m[i][j], m[i][C - 1 - j]);
        }
    }
}

bool isFilled(vector<vector<string>>& m) {
    vector<vector<bool>> seen(R, vector(C, false));
    int filled = 0;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if (m[i][j][k] == '#') {
                    if (seen[j][k]) return false;
                    else {
                        seen[j][k] = true;
                        ++filled;
                    }
                }
            }
        }
    }

    return filled == R * C;
}

bool dfs(vector<vector<string>>& m, int idx) {
    if (idx == 3) {
        if (isFilled(m)) return true;
        return false;
    }

    for(int di = -3; di <= 3; di++) {
        for(int dj = -3; dj <= 3; dj++) {
            bool flag = true;
            vector<string> nxt(R, "....");
            
            for(int i = 0; i < R && flag; i++) {
                for(int j = 0; j < C && flag; j++) {
                    if (m[idx][i][j] == '#') {
                        int ni = i + di;
                        int nj = j + dj;

                        if (ni < 0 || ni >= R || nj < 0 || nj >= C) {
                            flag = false;
                            break;
                        }

                        nxt[ni][nj] = '#';
                    }
                }
            }

            if (flag) {
                vector<string> prev = m[idx];
                m[idx] = nxt;
                if (dfs(m, idx + 1)) return true;
                m[idx] = prev;
            }
        }
    }

    return false;
}

void task() {
    vector<vector<string>> m(P, vector<string>(R));
    for(int i = 0; i < P; i++) {
        for(int j = 0; j < R; j++) {
            cin >> m[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        rotate(m[1]);
        for(int j = 0; j < 4; j++) {
            rotate(m[2]);
            if (dfs(m, 0)) {
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