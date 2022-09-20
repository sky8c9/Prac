#include <iostream>
#include <vector>
#include <string>

using namespace std;
void task() {
	int n = 10;
	vector<string> v(n);
	int a, b, c, d;
	a = b = c = d = 0;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) {
		bool find = false;
		for(int j = 0; j < v[i].length(); j++) {
			if (v[i][j] == '#') {
				a = b = i;
				c = d = j;

				while(d < n && v[i][d] == '#') ++d;
				while(b < n && v[b][j] == '#') ++b;

				find = true;
				break;			
			}
		}

		if (find) break;
	}

	cout << (a+1) << " " << b << endl;
	cout << (c+1) << " " << d << endl;
}

int main() {
	task();
	return 0;
}