#include <iostream>
#include <vector>
using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> p(n + 2);
	for(int i = 2; i <= n; i++) cin >> p[i];
	int cur = p[n];
	int ans = 1;
	while(cur != 1) {
		cur = p[cur];
		++ans;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}