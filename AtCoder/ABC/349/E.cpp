#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n = 3;
bool isGame(vector<vector<int>>& vals) {
    vector<int> cntR(n, 0);
    vector<int> cntC(n, 0);
    vector<int> cntD(2, 0);

    for(int i = 0; i < n; i++) {
        cntD[0] += vals[i][i];
        cntD[1] += vals[n - i - 1][i];

        for(int j = 0; j < n; j++) {
            cntR[i] += vals[i][j]; 
            cntC[j] += vals[i][j];
            
            if (cntR[i] == n || cntC[j] == n) return true;
        }

        if (cntD[0] == n || cntD[1] == n) return true;
    }

    return false;
}

bool canWin(vector<vector<int>>& board, vector<vector<int>>& vals, int filledCnt) {
    if (filledCnt == n * n) {
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum += vals[i][j] * board[i][j];
            }
        }

        return sum > 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (vals[i][j] == 0) {
                vector<vector<int>> nVals = vals;
                nVals[i][j] = 1;

                if (isGame(nVals)) return true;
                for(int ii = 0; ii < n; ii++) {
                    for(int jj = 0; jj < n; jj++) {
                        nVals[ii][jj] = -nVals[ii][jj];
                    }
                }

                if (!canWin(board, nVals, filledCnt + 1)) return true;
            }
        }
    }

    return false;
}

void task() {    
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> vals(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    bool ans = canWin(board, vals, 0);
    if (ans) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}

int main() {
    task();
    return 0;
}