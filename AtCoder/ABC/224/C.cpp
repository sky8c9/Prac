#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	vector<pair<ll, ll>> coords(n);
	for(int i = 0; i < n; i++) {
		cin >> coords[i].first >> coords[i].second;
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				auto& [xA,yA] = coords[i];
				auto& [xB,yB] = coords[j];
				auto& [xC,yC] = coords[k];

				if ((xA - xC) * (yA - yB) == (xA - xB) * (yA - yC)) continue;
				ans++;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}