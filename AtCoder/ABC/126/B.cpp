#include <iostream>
#include <string>
using namespace std;

void task() {
	string s;
	cin >> s;

	int first2 = (s[0] - '0') * 10 + (s[1] - '0');
	int last2 = (s[2] - '0') * 10 + (s[3] - '0');
	if (first2 <= 12 && last2 <= 12 && first2 > 0 && last2 > 0) cout << "AMBIGUOUS" << endl;
	else if (first2 <= 12 && first2 > 0) cout << "MMYY" << endl;
	else if (last2 <= 12 && last2 > 0) cout << "YYMM" << endl;
	else cout << "NA" << endl;
}

int main() {
	task();
	return 0;
}