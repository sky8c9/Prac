#include <iostream>
#include <vector>

using namespace std;

void task() {
    int scoreA = 0;
    int scoreB = 0;
    for(int i = 0; i < 9; i++) {
        int val;
        cin >> val;
        scoreA += val;
    }

    for(int i = 0; i < 8; i++) {
        int val;
        cin >> val;
        scoreB += val;
    }

    cout << (scoreA - scoreB + 1) << endl;
}

int main() {
    task();
    return 0;
}