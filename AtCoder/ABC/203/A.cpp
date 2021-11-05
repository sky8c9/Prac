#include <iostream>
 
using namespace std;
 
void task() {
	int a,b,c;
	cin >> a >> b >> c;
 
	int ans = 0;
	if (a == b) ans = c;
	else if (a == c) ans = b;
	else if (b == c) ans = a;
 
	cout << ans << endl;
}
 
int main() {
	task();
	return 0;
}