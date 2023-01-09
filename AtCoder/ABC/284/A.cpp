#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<string> s;
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        s.push_back(name);
    }

    reverse(s.begin(), s.end());
    for(string name : s) cout << name << endl;
}

int main() {
    task();
    return 0;
}