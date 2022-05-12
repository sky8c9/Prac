#include <iostream>
#include <vector>

using namespace std;

void task() {
	int h,w;
	cin >> h >> w;

	int r,c;
	cin >> r >> c;

	vector<int> didj{1,0,-1,0,1};
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		int ni = r + didj[i];
		int nj = c + didj[i + 1];

		if (ni >= 1 && ni <= h && nj >= 1 && nj <= w) ans++;
	}

	cout << ans << endl;

}

int main() {
	task();
	return 0;
}