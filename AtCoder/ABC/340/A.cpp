#include <iostream>

using namespace std;

void task() {
    int a, b, d;
    cin >> a >> b >> d;

    for(int i = a; i <= b; i+=d) {
        cout << i << " ";
    }
    
    cout << endl;
}

int main() {
    task();
}