#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

ll sum = 0;
int n, k, q;
multiset<int> top;
multiset<int> bot;
vector<int> a;

void balancer() {
    while(bot.size() && top.size() < k) {
        auto itr = bot.find(*prev(bot.end()));
        int val = *itr;
        bot.erase(itr);
        top.insert(val);
        sum += val;
    }

    while(bot.size() && top.size() && *top.begin() < *prev(bot.end())) {
        auto itrTop = top.begin();
        auto itrBot = prev(bot.end());
        int valTop = *itrTop;
        int valBot = *itrBot;
        top.erase(itrTop);
        bot.erase(itrBot);
        top.insert(valBot);
        bot.insert(valTop);
        sum += valBot - valTop;
    }
}

void add(int val) {
    bot.insert(val);
    balancer();
}

void remove(int val) {
    auto itrTop = top.find(val);
    auto itrBot = bot.find(val);

    if (itrTop == top.end()) {
        if (itrBot != bot.end()) bot.erase(itrBot);
    } else {
        top.erase(itrTop);
        sum -= val;
    }

    balancer();
}

void task() {
    cin >> n >> k >> q;
    a.resize(n, 0);
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        
        add(y);
        remove(a[x]);
       
        a[x] = y;
        cout << sum << endl;
    }
}

int main() {
    task();
    return 0;
}