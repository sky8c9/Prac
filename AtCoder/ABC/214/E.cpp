#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 1e9 + 2;

bool packable(vector<pair<int,int>>& intervals) {
  priority_queue<int, vector<int>, greater<int>> q;
  int firstEmpty = 1;

  for(auto&[l,r] : intervals) {
    while (firstEmpty < l && !q.empty()) {
      int closestR = q.top();
      if (firstEmpty <= closestR) {
        q.pop();
        firstEmpty++;
      } else return false;
    }

    firstEmpty = l;
    q.push(r);
  }

  return true;
}

void task() {
  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    vector<pair<int,int>> intervals(n);

    for(auto&[l,r] : intervals) {
      cin >> l >> r;
    }

    sort(intervals.begin(), intervals.end());
    intervals.emplace_back(MAX,MAX);

    bool ans = packable(intervals);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl; 
  }
}

int main() {
  task();
  return 0;
}