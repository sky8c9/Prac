#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ans;
    auto dfs = [&] (auto dfs, vector<int> v) -> void {
        if (v.size() == n) {
            ans.push_back(v);
            return;
        }

        for(int i = v.size() == 0 ? 1 : 10 + v.back(); i + 10 * (n - v.size() - 1) <= m; i++) {
            v.push_back(i);
            dfs(dfs, v);
            v.pop_back();
        }
    };

    dfs(dfs, {});

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int& val : ans[i]) cout << val << " ";
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}