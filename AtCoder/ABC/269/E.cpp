#include <iostream>

using namespace std;
void task() {
	int n;
	cin >> n;

	int l = 1;
	int h = n;

	while(l < h) {
		int mid = l + (h - l) / 2;
		printf("? %d %d %d %d\n", 1, mid, 1, n);
		int t; cin >> t;

		if (t == mid) l = mid + 1;
		else h = mid;
	}

	int x = l;
	l = 1; h = n;
	while(l < h) {
		int mid = l + (h - l) / 2;
		printf("? %d %d %d %d\n", 1, n, 1, mid);
		int t; cin >> t;

		if (t == mid) l = mid + 1;
		else h = mid;
	}

	int y = l;
	printf("! %d %d\n", x, y);

}

int main() {
	task();
	return 0;
}