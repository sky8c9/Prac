#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int a,b,c,d,e,f,x;
	cin >> a >> b >> c >> d >> e >> f >> x;

	int q1 = x / (a + c);
	int q2 = x / (d + f);

	int r1 = x % (a + c);
	int r2 = x % (d + f);

	int m1 = b * (a * q1 + min(a, r1));
	int m2 = e * (d * q2 + min(d, r2));

	if (m1 > m2) {
		cout << "Takahashi" << endl;
	} else if (m1 < m2) {
		cout << "Aoki" << endl;
	} else cout << "Draw" << endl;

}

int main() {
	task();
	return 0;
}