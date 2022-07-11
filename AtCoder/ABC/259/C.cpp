#include <iostream>
#include <vector>
#include <string>

using namespace std;
void task() {
	string s,t;
	cin >> s >> t;

	int i = 0;
	int j = 0;

	if (s.length() > t.length()) {
		cout << "No" << endl;
		return;
	} else {	
		for(; i < s.length(); i++, j++) {
			if (s[i] != t[j]) {
				cout << "No" << endl;
				return;
			} else {
				int cnt1 = 1;
				int cnt2 = 1;

				while(i + 1 < s.length() && s[i] == s[i + 1]) {
					cnt1++;
					i++;
				}

				while(j + 1 < t.length() && t[j] == t[j + 1]) {
					cnt2++;
					j++;
				}

				if (cnt1 > cnt2 || (cnt1 == 1 && cnt2 > 1)) {
					cout << "No" << endl;
					return;
				}

			}
		}
	}

	if (i == s.length() && j == t.length())
		cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}