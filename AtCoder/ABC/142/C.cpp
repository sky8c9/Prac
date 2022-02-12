#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<pair<int, int>> students;
	for(int i = 0; i < n; i++) {
		int count;
		cin >> count;

		students.emplace_back(count, i+1);
	}

	sort(students.begin(), students.end());
	for(int i = 0; i < n; i++) {
		cout << students[i].second << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}