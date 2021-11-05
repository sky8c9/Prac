#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void task() {
	int n;
	long long k;
	cin >> n >> k;
 
	vector<pair<long long,int>> friends(n);
	for(int i = 0; i < n; i++) {
		long long pos;
		int val;
		cin >> pos >> val;
		friends[i] = make_pair(pos, val);
	}
 
	sort(friends.begin(), friends.end());
	for(int i = 0; i < n; i++) {
		if (k >= friends[i].first) k += friends[i].second;
		else break;
	}
 
	cout << k << endl;
}
 
int main() {
	task();
	return 0;
}