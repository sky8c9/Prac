#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> points;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    for(int i = 0; i < n; i++) {
        int mxVal = 0;
        int mxId = -1;

        for(int j = 0; j < n; j++) {
            int valX = (points[j].first - points[i].first) * (points[j].first - points[i].first);
            int valY = (points[j].second - points[i].second) * (points[j].second - points[i].second);
            int val = valX + valY;

            if (val > mxVal) {
                mxVal = val;
                mxId = j;
            }
        }

        cout << mxId + 1 << endl;
    }
}

int main() {
    task();
    return 0;
}