#include <iostream>
#include <vector>

using namespace std;

int frontEnd(int num, bool reverse) {
	int end = num % 10;
	int front = end;

	while(num) {
		front = num;
		num /= 10;
	}

	if (reverse) return end * 10 + front;
	return front * 10 + end;
}

void task() {
	int n;
	cin >> n;

	vector<int> freq(100);
	for(int num = 1; num <= n; num++) {
		freq[frontEnd(num, false)]++;
	}

	int ans = 0;
	for(int num = 1; num <= n; num++) {
		ans += freq[frontEnd(num, true)];
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}