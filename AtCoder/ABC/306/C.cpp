#include <iostream>
#include <vector>

using namespace std;
int MAX = 1e5;

void task() {
    int n;
    cin >> n;

    vector<int> freq(MAX + 1);
    vector<int> ans;
    for(int i = 0; i < 3*n; i++) {
        int val;
        cin >> val;

        if (freq[val] == 1) ans.push_back(val); 
        ++freq[val];
    }

    for(int val : ans) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}