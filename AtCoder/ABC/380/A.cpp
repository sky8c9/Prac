#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> freq(10);
    while(n) {
        ++freq[n % 10];
        n /= 10;
    }

    if (freq[1] == 1 && freq[2] == 2 && freq[3] == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}