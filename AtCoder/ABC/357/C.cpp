#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "#" << endl;
        return;
    }

    vector<vector<string>> ans(6);
    ans[0].push_back("###");
    ans[0].push_back("#.#");
    ans[0].push_back("###");

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < ans[i].size(); k++) {
                string tmp = "";

                for(int l = 0; l < 3; l++) {
                    if (j == 1 && l == 1) {
                        tmp += string(ans[i][k].size(), '.');
                    } else {
                        tmp += ans[i][k];
                    }
                }

                ans[i + 1].push_back(tmp);
            }
        }
    }

    for(string s : ans[n - 1]) {
        cout << s << endl;
    }
}

int main() {
    task();
    return 0;
}