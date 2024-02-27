#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m;
    cin >> n >> m;
    vt<int> v(n);
    for (auto& s : v) cin >> s;
    unordered_map<int, unordered_set<int>> adjlist;
    vt<int> cost(n,0);
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adjlist[a].insert(b);
        cost[a] += v[b];
        adjlist[b].insert(a);
        cost[b] += v[a];
    }

    int ans = 0;
    vt<int> removed(n,0);
    // need to remove n parts
    for (int i = 0; i < n; ++i) {
        int max_val = INT_MIN;
        int torem;
        for (int j = 0; j < n; ++j) {
            if (!removed[j]) {;
                if (v[j] > max_val) {
                    max_val = v[j];
                    torem = j;
                }
            }
        }
        ans += cost[torem];
        removed[torem] = 1;
        for (auto& nei : adjlist[torem]) {
            cost[nei] -= v[torem];
            adjlist[nei].erase(torem);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}