#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    cin >> n;

    int ans = 0;
    while(n--) {
        string s;
        cin >> s;

        if (s == "Takahashi") ++ans;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}