#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
  
    map<ll, set<ll>> mx;
    map<ll, set<ll>> my;
    while(n--) {
        ll x, y;
        cin >> x >> y;
        mx[x].insert(y);
        my[y].insert(x);
    }

    ll ans = 0;
    auto del = [&] (ll start, ll end, ll pos, map<ll, set<ll>>& m1, map<ll, set<ll>>& m2) -> void {
        if (start > end) swap(start, end);
        auto s = m1[pos].lower_bound(start);
        auto e = m1[pos].end();
        for(auto itr = s; itr != e && *itr <= end;) {
            m2[*itr].erase(pos);
            m1[pos].erase(itr++);
            ++ans;
        }
    };

    ll curx = x;
    ll cury = y;
    while(m--) {
        char d;
        int c;
        cin >> d >> c;

        ll nx = curx;
        ll ny = cury;
        if (d == 'U') {
            ny = cury + c;
            del(cury, ny, curx, mx, my);
        } else if (d == 'D') {
            ny = cury - c;
            del(cury, ny, curx, mx, my);
        } else if (d == 'L') {
            nx = curx - c;
            del(curx, nx, cury, my, mx);
        } else if (d == 'R') {
            nx = curx + c;
            del(curx, nx, cury, my, mx);
        }
        
        curx = nx;
        cury = ny;
    }

    cout << curx << " " << cury << " " << ans << endl;
}

int main() {
    task();
    return 0;
}