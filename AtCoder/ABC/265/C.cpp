#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
using ll = long long;

void task() {
	int h,w;
	cin >> h >> w;

 	vector<bool> seen(500 * 500 + 1);
 	vector<string> grid(h);
 	for(int i = 0; i < h; i++) {
 		cin >> grid[i];
 	}

 	int i = 0;
 	int j = 0;
 	while(true) {
 		int ni = i;
 		int nj = j;
 		if (grid[i][j] == 'R') nj += 1;
 		else if (grid[i][j] == 'L') nj -= 1;
 		else if (grid[i][j] == 'U') ni -= 1;
 		else if (grid[i][j] == 'D') ni += 1;

 		if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
 			cout << i + 1 << " " << j + 1 << endl;
 			return;
  		}

  		if (seen[i * w + j]) {
  			 cout << -1 << endl;
  			return;
  		}

  		seen[i * w + j] = true;
  		i = ni;
  		j = nj;
 	}
}
 
int main() {
	task();
	return 0;
}