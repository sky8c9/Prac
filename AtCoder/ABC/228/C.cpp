#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
	int n,k;
	cin >> n >> k;

	vector<int> points(n);
	vector<int> spoints(n);

	for(int i = 0; i < n; i++) {
		int p1,p2,p3;
		cin >> p1 >> p2 >> p3;
		points[i] = p1 + p2 + p3;
		spoints[i] = points[i];
	}

	sort(spoints.begin(),spoints.end());
	int kpoint = spoints[n-k];

	for(int point : points) {
		if (point + 300 >= kpoint) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main() {
	task();
	return 0;
}