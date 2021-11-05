#include <iostream>
 
using namespace std;
 
void task() {
	int n, k;
	cin >> n >> k;
 
	int ans = n * (k * (k + 1) / 2) + k * (100 * (n * (n+1) / 2));
	
	cout << ans << endl;
}
 
int main() {
	task();
	return 0;
}