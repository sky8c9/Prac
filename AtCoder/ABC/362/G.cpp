#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    pair<int, int> val;
    int index;
    Node() : val({-1, -1}), index(-1) {}
};

bool cmp (Node a, Node b) {
    return a.val < b.val;
}

struct SA {
    string s;
    int n;
    vector<Node> sa;
    vector<int> ranks;

    SA(string str) {
        s = str;
        n = s.size();
        sa.resize(n);
        ranks.resize(n);

        for(int i = 0; i < n; i++) {
            sa[i].val = {s[i], s[i]};
            sa[i].index = i;
        }

        update();
    }

    void update() {
        sort(sa.begin(), sa.end(), cmp);
        for(int i = 0; i < n - 1; i++) {
            ranks[sa[i + 1].index] = ranks[sa[i].index];
            if (sa[i + 1].val > sa[i].val) ++ranks[sa[i + 1].index];
        }
    }

    void build() {
        for(int len = 1; len < s.size(); len*=2) {
            for(auto &[val, idx] : sa) {
                int nidx = (idx + len) % n;
                val = {ranks[idx], ranks[nidx]};
            }
            update();
        }
    }
};

void task() {
    string s;
    cin >> s;

    SA suffix_array(s + '$');
    suffix_array.build();

    int q;
    cin >> q;

    auto findT = [&] (string t) {
        int lo = 0;
        int hi = suffix_array.n;

        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            string cur = s.substr(suffix_array.sa[mid].index, t.size());

            if (cur < t) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    };
    
    while(q--) {
        string t;
        cin >> t;

        int ans = findT(t + '|') - findT(t);
        cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}