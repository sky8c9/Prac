#include <iostream>
#include <vector>

using namespace std;

void task() {
    vector<vector<bool>> seen(100, vector<bool>(100, false));
    int n;
    cin >> n;

    int ans = 0;
    while(n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int i = c; i < d; i++) {
            for(int j = a; j < b; j++) {
                if (seen[i][j]) continue;
                else {
                    ++ans;
                    seen[i][j] = true;
                }
            }
        }
    }    
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}