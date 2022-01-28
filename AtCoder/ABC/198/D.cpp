#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
unordered_map<char, int> m;
vector<bool> used(10);
string charSet;
string s1,s2,s3;

ll toNum(string s) {
	if (m[s[0]] == 0) return -1;
	ll num = 0;
	for(int i = 0; i < s.length(); i++) {
		num = num * 10 + m[s[i]];
	}
	return num;
}

bool dfs(int index) {
	if (index == charSet.length()) {
		ll v1 = toNum(s1);
		ll v2 = toNum(s2);
		ll v3 = toNum(s3);

		if (v1 == -1 || v2 == -1 || v3 == -1) return false;
		if (v1 + v2 != v3) return false;
		else {
			cout << v1 << endl;
			cout << v2 << endl;
			cout << v3 << endl;
			return true;
		}
	}

	if (m[charSet[index]]) return dfs(index + 1);
	for(int i = 0; i < 10; i++) {
		if (used[i]) continue;
		used[i] = true;
		m[charSet[index]] = i;
		if (dfs(index + 1)) return true;
		m.erase(charSet[index]);
		used[i] = false;
	}

	return false;
}

void task() {
	cin >> s1 >> s2 >> s3;
	unordered_set<char> hset;
	for(char c : s1) hset.insert(c);
	for(char c : s2) hset.insert(c);
	for(char c : s3) hset.insert(c);

	if (hset.size() > 10) {
		cout << "UNSOLVABLE" << endl;
		return;
	}

	for(char c : hset) charSet += c;
	if (!dfs(0)) cout << "UNSOLVABLE" << endl;
}

int main() {
	task();
	return 0;
}