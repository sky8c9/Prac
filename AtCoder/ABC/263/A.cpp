#include <iostream>
#include <unordered_map>
using namespace std;

void task() {
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;

	unordered_map<int, int> freq;
	freq[a]++; freq[b]++;
	freq[c]++; freq[d]++; freq[e]++;
	if (freq.size() == 2 && (freq[a] == 3 || freq[b] == 3 || freq[c] == 3)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	task();
	return 0;
}