#include <iostream>
#include <vector>

using namespace std;

void task() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int cnt = 0;
        while(n--) {
            int num; cin >> num;
            cnt += num & 1;
        }
        
        cout << cnt << endl; 
    }
}

int main() {
    task();
    return 0;
}