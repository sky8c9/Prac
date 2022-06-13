#include <iostream>
#include <vector>
using namespace std;

void task() {
	int r,c;
	cin >> r >> c;

	vector<vector<int>> M(2, vector<int>(2));
	cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1];

	cout << M[r-1][c-1] << endl;
}

int main() {
	task();
	return 0;
}