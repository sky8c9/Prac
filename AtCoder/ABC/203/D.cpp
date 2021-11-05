#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void matrixIntegral(const vector<vector<int>>& in, vector<vector<int>>& out, int val) {
	for(int i = 1; i < out.size(); i++) {
		for(int j = 1; j < out.size(); j++) {
			out[i][j] = in[i-1][j-1] > val ? 1 : 0;
		}
	}
 
	for(int i = 1; i < out.size(); i++) {
		for(int j = 1; j < out.size(); j++) {
			out[i][j] += out[i-1][j] + out[i][j-1] - out[i-1][j-1];
		}
	}
}
 
void task() {
	int n,k;
	cin >> n >> k;
 
	vector<vector<int>> in(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int val;
			cin >> val;
			in[i][j] = val;
		}
	}
 
	int lo = 0;
	int hi = 1e9;
	int median = (k * k) / 2 + 1;
 
	while(lo < hi) {
		int mid = lo + (hi - lo) / 2;
		vector<vector<int>> out(n + 1, vector<int>(n + 1));
 
		matrixIntegral(in, out, mid);
		bool flag = false;	
 
		for(int i = 0; i < n - k + 1; i++) {
			for(int j = 0; j < n - k + 1; j++) {
				int cnt = out[i+k][j+k]- out[i][j+k] - out[i+k][j] + out[i][j];
				if (cnt < median) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
 
		if (flag) hi = mid;
		else lo = mid + 1;
	}
 
	cout << lo << endl;
}
 
int main() {
	task();
	return 0;
}