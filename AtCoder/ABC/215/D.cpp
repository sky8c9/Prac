#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> pfactor;
void find_prime_factor(int a) {
	for(int i = 2; i * i <= a; i++) {
		while (a % i == 0) {
			pfactor.insert(i);
			a /= i;
		}
	}

	if (a != 1) pfactor.insert(a);
}

void task() {
	int n,m;
	cin >> n >> m;

	vector<bool> ans(m+1, true);
	vector<int> a(n);
	for(int& val : a) {
		cin >> val;
	}

	for(int val : a) {
		find_prime_factor(val);
	}

	int count = m;
	for(int p : pfactor) {
		for(int i = p; i <= m; i+=p) {
			if (ans[i] == false) continue;	
			ans[i] = false;
			count--;
		}
	}

	cout << count << endl;
	for(int i = 1; i <= m; i++) {
		if (ans[i]) cout << i << endl;
	}
}

int main() {
	task();
	return 0;
}