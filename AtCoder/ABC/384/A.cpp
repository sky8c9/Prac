#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    char c1, c2;
    string s;
    cin >> n >> c1 >> c2 >> s;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] != c1) s[i] = c2;
    }

    cout << s << endl;
}

int main() {
    task();
    return 0;
}