#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool find(const vector<int>& delta, int target) {
    unordered_set<int> seen;
    seen.insert(0);

    for(int d : delta) {
        unordered_set<int> tmp;
        for(int val : seen) {
            tmp.insert(val + d);
            tmp.insert(val - d);
        }
        seen = tmp;
    }

    return seen.count(target);
}

void task() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> dX;
    vector<int> dY;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (!i) {
            x-=a;
            continue;
        }

        if (i & 1) dY.push_back(a);
        else dX.push_back(a);
    }

    bool seenX = find(dX, x); 
    bool seenY = find(dY, y);
    if (seenX && seenY) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}