#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void task() {
	int n;
	cin >> n;

	int first = -1;
	int second = -1;
	string firstS;
	string secondS;

	for(int i = 0; i < n; i++) {
		int h;
		string s;

		cin >> s >> h;
		if (first == -1 || h > first) {
			second = first;
			secondS = firstS;
			first = h;
			firstS = s;
		} else if (second == -1 || h > second) {
			second = h;
			secondS = s;
		}
	}

	cout << secondS << endl;
}

int main() {
	task();
	return 0;
}