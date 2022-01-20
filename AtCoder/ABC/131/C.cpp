#include <iostream>
#include <unordered_set>

using namespace std;
long long gcd(long long a, long long b) {
	if (a == 0) return b;
	return gcd(b % a, a); 
}

long long findMultiple(long long a, long long b, long long x) {
	long long lo = (a - 1) / x;
	long long hi = b / x;
	return hi - lo;	
}

void task() {
	long long a,b,c,d;
	cin >> a >> b >> c >> d;

	long long gcdCD = gcd(c,d);
	long long mc = findMultiple(a,b,c);
	long long md = findMultiple(a,b,d);
	long long mcd = findMultiple(a, b, c / gcdCD * d);
	cout << (b - a + 1) - (mc + md - mcd) << endl;
	
}

int main() {
	task();
	return 0;
}