#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), [](string a, string b) -> bool {
        return a.size() < b.size();
    });

    for(int i = 0; i < n; i++) {
        cout << v[i];
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}