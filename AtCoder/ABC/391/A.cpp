#include <iostream>
#include <string>

using namespace std;

void task() {
    string d;
    cin >> d;
    for(int i = 0; i < d.size(); i++) {
        if (d[i] == 'N') cout << 'S';
        else if (d[i] == 'S') cout << 'N';
        else if (d[i] == 'W') cout << 'E';
        else cout << 'W';
    }
    cout << endl;
}

int main() {
    task();
    return 0;
}