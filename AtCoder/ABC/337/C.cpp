#include <iostream>
#include <vector>
using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> next(n + 1, 0);
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        
        if (val == -1) cur = i;
        else next[val] = i;
    }

    for(int i = 1; i <= n; i++) {
        cout << cur << " ";
        cur = next[cur];
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}