#include <iostream>

using namespace std;

void task() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	// ans > a / (cd - b)
	long long nume = a;
	long long deno = c * d - b;

	if (deno <= 0) cout << -1 << endl;
	else cout << (nume + deno - 1) / deno << endl;

}

int main() {
	task();
	return 0;
}