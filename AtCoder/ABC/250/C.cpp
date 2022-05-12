#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void task() {
	int n,q;
	cin >> n >> q;

	vector<int> i2v(n+1);
	vector<int> v2i(n+1);
	for(int i = 1; i <= n; i++) {
		i2v[i] = i;
		v2i[i] = i;
	}

	for(int i = 0; i < q; i++) {
		int x;
		cin >> x;

		int pos = v2i[x];
		int npos = pos;

		if (pos >= n) --npos;
		else ++npos;
		swap(i2v[pos], i2v[npos]);
		swap(v2i[i2v[pos]], v2i[i2v[npos]]);
	} 

	for(int i = 1; i <= n; i++) {
		cout << i2v[i] << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}