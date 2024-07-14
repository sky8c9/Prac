#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;

    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    vector<pair<int, int>> x{{a,d}, {g, j}};
    vector<pair<int, int>> y{{b,e}, {h, k}};
    vector<pair<int, int>> z{{c,f}, {i, l}};

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    bool flag = true;
    if (x[1].first >= x[0].second) flag = false;
    if (y[1].first >= y[0].second) flag = false;
    if (z[1].first >= z[0].second) flag = false;

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}