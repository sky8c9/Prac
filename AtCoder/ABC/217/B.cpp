#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void task() {
	string s1,s2,s3;
	unordered_set<string> seen;
	seen.insert("ABC");seen.insert("ARC");
	seen.insert("AGC");seen.insert("AHC");

	cin >> s1 >> s2 >> s3;
	seen.erase(s1);
	seen.erase(s2);
	seen.erase(s3);

	cout << *seen.begin() << endl;
}

int main() {
	task();
	return 0;
}