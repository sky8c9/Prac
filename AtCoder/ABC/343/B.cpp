#include <iostream>
#include <vector>
using namespace std;

void task() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j]) cout << j + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}