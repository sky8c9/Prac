#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int v, b, c;
};

bool checked(vector<vector<Edge>>& adjL, double x) {
    int n = adjL.size();
    vector<double> vals(n, -1e9);
    vals[0] = 0;
    
    for(int u = 0; u < n; u++) {
        for(auto[v, b, c] : adjL[u]) {
            vals[v] = max(vals[v], vals[u] + b - c * x);
        }
    }

    return vals[n - 1] >= 0;
}

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adjL(n);
    for(int i = 0; i < m; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        --u; --v;
        adjL[u].push_back((Edge){v, b, c});
    }

    double lo = 0;
    double hi = 1e4;
    for(int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (checked(adjL, mid)) lo = mid;
        else hi = mid;
    }

    printf("%.9f\n", lo);
}

int main() {
    task();
    return 0;
}