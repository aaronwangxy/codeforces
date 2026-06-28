#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int dfs(int node, vt<vt<int>>& adjlist, vt<int>& heights) {
    int height = 1;
    for (auto nei : adjlist[node]) {
        height = max(height, 1 + dfs(nei, adjlist, heights));
    }
    heights[node] = height;
    return height;
}

void dfs2(int node, vt<vt<int>>& adjlist, vt<int>& heights, int& ans) {
    ans += 1; // itself
    vt<int> children_heights;
    for (auto nei : adjlist[node]) {
        children_heights.push_back(heights[nei]);
        dfs2(nei, adjlist, heights, ans);
    }
    if (children_heights.size() <= 1) {
        return;
    }
    sort(children_heights.begin(), children_heights.end());
    int tallest = children_heights[children_heights.size()-1];
    int tallest_2 = children_heights[children_heights.size()-2];
    ans += tallest_2;
}

/*
When would guilds from a node be different than those of its children?
    - if the node has one child, then it only offers one unique guild (itself)

think bfs. a node has a unique guild at depth h > 0 when
    - there are 2+ children with depth h from 
*/
void solve() {
    int n;
    cin >> n;
    vt<int> p(n+1);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
    }

    vt<vt<int>> adjlist(n+1);
    for (int i = 2; i <= n; ++i) {
        adjlist[p[i]].push_back(i);
    }

    vt<int> heights(n+1);
    dfs(1, adjlist, heights);

    int ans = 0;
    dfs2(1, adjlist, heights, ans);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}