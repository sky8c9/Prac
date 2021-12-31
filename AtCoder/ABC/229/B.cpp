#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	ll a,b;
	cin >> a >> b;

	while(a > 0 && b > 0) {
		int da = a % 10;
		int db = b % 10;
		if (da + db > 9) {
			cout << "Hard" << endl;
			return;
		} 
		a /= 10;
		b /= 10;
	}

	cout << "Easy" << endl;
}

int main() {
	task();
	return 0;
}