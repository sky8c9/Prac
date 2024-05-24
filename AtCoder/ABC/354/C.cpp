#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Node {
    int a;
    int c;
    int idx;
};

bool cmp (Node n1, Node n2) {
    return n1.a < n2.a;
}

void task() {
    int n;
    cin >> n;

    vector<Node> v;
    set<int> ans;
    for(int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;

        v.push_back({a, c, i});
        ans.insert(i);
    }

    sort(v.begin(), v.end(), cmp);
    vector<Node> cur;
    for(int i = 0; i < n; i++) {
        while (cur.size() && v[i].c < cur.back().c) {
            ans.erase(cur.back().idx);
            cur.pop_back();
        } 
        
        cur.push_back(v[i]);
    }

    cout << ans.size() << endl;
    for(int val : ans) {
        cout << val + 1 << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}