#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	string x;
	int n;
	cin >> x >> n;

	unordered_map<char,char> m1,m2;
	for(int i = 0; i < x.length(); i++) {
		m1['a' + i] = x[i];
		m2[x[i]] = 'a' + i;
	}

	vector<string> names(n);
	for(string& name : names) {
		cin >> name;
		for(char& c : name) {
			c = m2[c];
		}
	}

	sort(names.begin(), names.end());
	for(string& name : names) {
		for(char& c : name) {
			c = m1[c];
		}
		cout << name << endl;
	}
}

int main() {
	task();
	return 0;
}