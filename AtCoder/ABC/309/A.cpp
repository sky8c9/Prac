#include <iostream>

using namespace std;

void task() {
    int a, b;
    cin >> a >> b;

    if (b - a == 1 && a + b != 7 && a + b != 13) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl;
    }

}

int main() {
    task();
    return 0;
}