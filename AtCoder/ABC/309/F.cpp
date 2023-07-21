#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 1e9 + 1;

struct SegTree_Min {
	vector<int> tree;
	int n;

	SegTree_Min(int size) {
		n = size;
		while(n != 0 && (n & (n-1)) != 0) n++;
		tree = vector<int>(2*n, MAX);
	}

    int get(int index) {
        return tree[n + index];
    }

	void update(int index, int val) {
		tree[n + index] = val;
		for(int i = (n + index) / 2; i > 0; i /= 2) {
			tree[i] = min(tree[2*i], tree[2*i+1]);
		}
	}

	int query(int index, int curL, int curR, int qLeft, int qRight) {
		if (curR < qLeft || curL > qRight) return MAX;
		if (curL >= qLeft && curR <= qRight) return tree[index];
		
		int mid = curL + (curR - curL) / 2;
		return min(query(2*index, curL, mid, qLeft, qRight), query(2*index+1, mid + 1, curR, qLeft, qRight));
	}
};

void task() {
    int n;
    cin >> n;
    
    map<int, vector<pair<int, int>>> xyz;
    map<int, int> m;
    while(n--) {
        vector<int> tuple(3);
        cin >> tuple[0] >> tuple[1] >> tuple[2];
        
        sort(tuple.begin(), tuple.end());
        xyz[tuple[0]].emplace_back(tuple[1], tuple[2]);
        m[tuple[1]] = 0;
    }

    int val = 0;
    for(auto[k, _] : m) {
        m[k] = val++;
    }

    SegTree_Min segT(m.size());
    for(auto[x, yz] : xyz) {
        for(auto[y, z] : yz) {
            int mn = segT.query(1, 0, segT.n - 1, 0, m[y] - 1);
            if (mn < z) {
                cout << "Yes" << endl;
                return;
            }
        }

        for(auto[y, z] : yz) {
            segT.update(m[y], min(z, segT.get(m[y])));
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}