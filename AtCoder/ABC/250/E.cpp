#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	unordered_set<int> seenA;
	unordered_set<int> seenB;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	int posA = 0;
	int posB = 0;
	vector<int> matchA(n);
	vector<int> matchB(n);
	for(int i = 1; i <= n; i++) {
		seenA.insert(a[i]);
		seenB.insert(b[i]);

		while(posB < n && seenA.count(b[posB + 1])) ++posB;
		while(posA < n && seenB.count(a[posA + 1])) ++posA;

		matchA[i] = posB;
		matchB[i] = posA; 
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;

		if (matchA[x] >= y && matchB[y] >= x) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

}

int main() {
	task();
	return 0;
}