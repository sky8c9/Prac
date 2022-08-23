#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
void task() {
	ll n,m,t;
	cin >> n >> m >> t;
 
	vector<ll> a(n);
	unordered_map<ll,ll> b;
	for(int i = 1; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		ll x,y;
		cin >> x >> y;
		b[x-1] = y;
	}
 
	for(int i = 1; i < n; i++) {
		t -= a[i];
		if (t <= 0) {
			cout << "No" << endl;
			return;
		}
		t += b[i];
	}
 
	cout << "Yes" << endl;
}
 
int main() {
	task();
	return 0;
}