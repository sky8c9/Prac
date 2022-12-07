#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> s(n);
    for(int&val : s) cin >> val;

    int sum = s[0];
    cout << sum << " ";
    for(int i = 1; i < n; i++) {
        int val = s[i] - sum;
        cout << val << " ";
        sum += val; 
    }
    cout << endl;
}

int main() {
    task();
    return 0;
}