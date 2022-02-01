#include <iostream>
#include <string>
#include <deque>
using namespace std;

void task() {
	int n;
	string s;
	cin >> n >> s;

	deque<int> ans;
	ans.push_back(n);
	
	for(int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == 'L') ans.push_back(i); 
		else ans.push_front(i);
	}

	while(!ans.empty()) {
		cout << ans.front() << " ";
		ans.pop_front();
	}

}

int main() {
	task();
	return 0;
}