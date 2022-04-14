#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<vector<string>> name(n);
	for(int i = 0; i < n; i++) {
		string lname;
		string fname;
		cin >> lname >> fname;

		name[i].push_back(lname);
		name[i].push_back(fname);
	}

	for(int i = 0; i < n; i++) {
		int cnt = 0;

		for(int j = 0; j < name[i].size(); j++) {
			for(int k = 0; k < n; k++) {
				if (k == i) continue; 
				if (name[i][j] == name[k][0] || name[i][j] == name[k][1]) {
					cnt++;
					break;
				}
			}
		}

		if (cnt == 2) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}