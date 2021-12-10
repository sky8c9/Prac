#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 4;
const vector<int> DiDj{1,0,-1,0,1};

vector<vector<int>> villages(SIZE, vector<int>(SIZE));
vector<vector<bool>> bounded(SIZE, vector<bool>(SIZE));
vector<vector<int>> coord(SIZE + 1, vector<int>(SIZE + 1));
vector<vector<bool>> seen(SIZE + 1, vector<bool>(SIZE + 1));
int ans = 0;

// true if all villages are bounded, false otherwise
bool isBounded() {	
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			if (villages[i][j] && !bounded[i][j]) {
				return false;
			}
		}
	}
	return true;
}

// toggle bounded status: odd = bounded, even = unbounded
void toggle(int i, int j) {
	for(int k = i; k < SIZE; k++) {
		bounded[k][j] = !bounded[k][j];
	}
}

// explore fencing options
void dfs(int bi, int bj, int i, int j) {
	seen[i][j] = true;

	for(int k = 0; k < DiDj.size() - 1; k++) {
		int ni = i + DiDj[k];
		int nj = j + DiDj[k+1];
		if (ni < 0 || nj < 0 || ni >= SIZE + 1 || nj >= SIZE + 1) continue;

		if (ni == i) toggle(i,min(j,nj));

		if (seen[ni][nj]) {
			if (ni == bi && nj == bj && isBounded()) ans += 1;
		} else dfs(bi,bj,ni,nj);	

		if (ni == i) toggle(i,min(j,nj));
	}

	seen[i][j] = false;
}

void task() {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			cin >> villages[i][j];
		}
	}

	for(int i = 0; i <= SIZE; i++) {
		for(int j = 0; j <= SIZE; j++) {
			// possible ways to fence villages starting at coordinate (i,j)
			dfs(i,j,i,j);

			// prevent any future paths from reaching this coordinate again - eliminating duplicates
			seen[i][j] = true;
		}
	}
	
	// cw and ccw paths are counted twice; thus, divide 2
	cout << ans / 2 << endl;
}

int main() {
	task();
	return 0;
}