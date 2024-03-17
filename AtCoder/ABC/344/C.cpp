#include <iostream>
#include <vector>
#include <set>

using namespace std;

void task() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val : a) cin >> val;

    int m;
    cin >> m;
    vector<int> b(m);
    for(int&val : b) cin >> val;

    int l;
    cin >> l;
    vector<int> c(l);
    for(int&val : c) cin >> val;

    set<int> seen;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < l; k++) {
                seen.insert(a[i] + b[j] + c[k]);
            }
        }
    }

    int q;
    cin >> q;
    vector<string> ans;
    while(q--) {
        int x;
        cin >> x;

        if (seen.count(x)) ans.push_back("Yes");
        else ans.push_back("No");  
    }

    for(string& val : ans) cout << val << endl;
}

int main() {
    task();
    return 0;
}