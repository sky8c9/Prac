#include <iostream>
#include <vector>
#include <string>

using namespace std;
void task() {
	int n, a, b;
	cin >> n >> a >> b;

	vector<string> ans(a * n);
	for(int i = 0; i < a * n; i++) {
		for(int j = 0; j < b * n; j++) {
			char c = ((i / a) + (j / b)) & 1 ? '#' : '.';
			
			ans[i].push_back(c);
		}

		cout << ans[i] << endl;
	}
}

int main() {
	task();
	return 0;
}
