#include <iostream>
#include <vector>
#include <set>

using namespace std;
void task() {
    int n,m;
    cin >> n >> m;

    vector<set<int>> adjL(n + 1);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        
        adjL[a].insert(b);
        adjL[b].insert(a);
    }

    for(int i = 1; i <= n; i++) {
        cout << adjL[i].size();
        for(int nb : adjL[i]) cout << " " << nb;
        cout << endl; 
    }
}

int main() {
    task();
    return 0;
}