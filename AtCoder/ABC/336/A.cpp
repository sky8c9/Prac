#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    cin >> n;

    string ans = "L";
    for(int i = 0; i < n; i++) {
        ans += 'o';
    }

    ans += "ng";
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}