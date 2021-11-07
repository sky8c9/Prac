#include <iostream>
#include <map>

using namespace std;

void task() {
	map<int,int> freq;
	long long n;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		freq[val]++;
	}

	long long total = (n * (n-1)) / 2;
	for(const auto& [key,val] : freq) {
		if (val > 1) {
			total -= (long long) val * (val - 1) / 2;
		}
	}
	
	cout << total << endl;
}

int main() {
	task();
	return 0;
}