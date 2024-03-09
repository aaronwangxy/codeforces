#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void dfs(pair<int,int> node, set<pair<int,int>>& visited, map<pair<int,int>, vt<pair<int,int>>>& adjlist) {
    visited.insert(node);
    for (auto& nei : adjlist[node]) {
        if (visited.find(nei) == visited.end())
            dfs(nei, visited, adjlist);
    }
}

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> points(n, vt<int> (2));
    for (auto& v:points)
        cin >> v[0] >> v[1];
    map<pair<int,int>, vt<pair<int,int>>> adjlist;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (points[j][0] == points[i][0] || points[j][1] == points[i][1]) {
                adjlist[make_pair(points[i][0],points[i][1])].emplace_back(make_pair(points[j][0],points[j][1]));
                adjlist[make_pair(points[j][0],points[j][1])].emplace_back(make_pair(points[i][0],points[i][1]));
            }
        }
    }

    int ans = -1;
    set<pair<int,int>> visited;
    for (int i = 0; i < n; ++i) {
        pair<int,int> k = make_pair(points[i][0],points[i][1]);
        if (visited.find(k) == visited.end()) {
            ans += 1;
            visited.insert(k);
            dfs(k, visited, adjlist);
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