#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    string s;
    cin >> n >> s;

    string ans;
    
    for(int i = 0; i < n; i++) {
        ans.push_back(s[i]);
        ans.push_back(s[i]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}