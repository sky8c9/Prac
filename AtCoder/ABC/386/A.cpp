#include <iostream>
#include <unordered_map>

using namespace std;

void task() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    unordered_map<int, int> m;
    ++m[a]; ++m[b]; ++m[c]; ++m[d];

    if (m.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}