#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
	ll n;
	cin >> n;

	vector<int> pos;
	for(int i = 0; i < 60; i++) {
		if ((n >> i) & 1) pos.push_back(i);
	}

	for(int i = 0; i < (1 << pos.size()); i++) {
		ll val = 0;

		for(int j = 0; j < pos.size(); j++) {
			if ((i >> j) & 1) val |= ( 1ll << pos[j]); 
		}
		
		cout << val << endl;
	}

}

int main() {
	task();
	return 0;
}
