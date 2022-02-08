#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
void task() {
	string s;
	cin >> s;

	unordered_map<string, int> m;
	m["SUN"]=7;m["MON"]=6;m["TUE"]=5;m["WED"]=4;
	m["THU"]=3;m["FRI"]=2;m["SAT"]=1;
	
	cout << m[s] << endl;
}

int main() {
	task();
	return 0;
}