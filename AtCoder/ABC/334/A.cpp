#include <iostream>

using namespace std;

void task() {
    int b, g;
    cin >> b >> g;
    if (b > g) cout << "Bat" << endl;
    else if (g > b) cout << "Glove" << endl;
}

int main() {
    task();
    return 0;
}