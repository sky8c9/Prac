#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int MAX = 1e8;
const int MIN = -1e8;

struct SegTree_Max {
	vector<int> tree;
	int n;

	SegTree_Max(int size) {
		n = size;
		while(n != 0 && (n & (n-1)) != 0) n++;
		tree = vector<int>(2*n, MIN);
	}

	void update(int index, int val) {
		tree[n + index] = val;
		for(int i = (n + index) / 2; i > 0; i /= 2) {
			tree[i] = max(tree[2*i], tree[2*i+1]);
		}
	}

	int query(int index, int curL, int curR, int qLeft, int qRight) {
		if (curR < qLeft || curL > qRight) return MIN;
		if (curL >= qLeft && curR <= qRight) return tree[index];
		
		int mid = curL + (curR - curL) / 2;
		return max(query(2*index, curL, mid, qLeft, qRight), query(2*index+1, mid + 1, curR, qLeft, qRight));
	}
};

void task() {
    int n;
    cin >> n;

    vector<int> p(n);
    unordered_map<int, int> ans;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        ans[p[i]] = MAX;
    }

    for(int i = 0; i < 2; i++) {
        SegTree_Max seg_mx1(n);
        SegTree_Max seg_mx2(n);

        for(int i = 0; i < n; i++) {
            int c1 = p[i] + i;
            int c2 = -p[i] + i;
            int q1 = seg_mx1.query(1, 1, seg_mx1.n - 1, 1, p[i]);
            int q2 = seg_mx2.query(1, 1, seg_mx2.n - 1, p[i] + 1, seg_mx2.n - 1);

            ans[p[i]] = min(ans[p[i]], q1 == MIN ? ans[p[i]] : c1 - q1);
            ans[p[i]] = min(ans[p[i]], q2 == MIN ? ans[p[i]] : c2 - q2);

            seg_mx1.update(p[i], c1);
            seg_mx2.update(p[i], c2);
        }

        reverse(p.begin(), p.end());
    }

    for(int i = 0; i < n; i++) {
        cout << ans[p[i]] << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}