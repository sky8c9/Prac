#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    for(int i = s.size() - 2; i >= 0; i--) {
        if (s[i] == 'W' && s[i + 1] == 'A') {
            s[i] = 'A';
            s[i + 1] = 'C'; 
        }
    }

    cout << s << endl;
}

int main() {
    task();
    return 0;
}