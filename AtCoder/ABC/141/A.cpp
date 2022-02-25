#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	if (s == "Sunny") cout << "Cloudy" << endl;
	else if (s == "Cloudy") cout << "Rainy" << endl;
	else cout << "Sunny" << endl; 
}

int main() {
	task();
	return 0;
}