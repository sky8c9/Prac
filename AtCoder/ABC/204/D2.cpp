#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

/*
	Ex: position ith = 1 if the number was seen

	1	......00000001 // start with 0
	2	...00000001... // left shift 3 (add 3)
	3	...00000001001 // 1 | 2 = seen 0 and 3
	4	.00000001001.. // left shift 2 (add 2)
	5	.0000000101101 // 3 | 4 = seen 0, 2, 3, 5
*/

void task() {
	bitset<100001> seen;
	int n;
	int sum;

	seen[0] = 1;
	sum = 0;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		seen |= (seen << val);
		sum += val;
	}

	int ans = 100000;
	for(int i = 1; i <= 100000; i++) {
		if (seen[i]) {
			ans = min(ans, max(i, sum - i));
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}