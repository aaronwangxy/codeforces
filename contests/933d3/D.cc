#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void dfs(int pos, int curr, vt<int>& throwlist, vt<char>& throwid, set<int>& ans, int mod, set<vt<int>>& visited) {
    if (curr == throwlist.size()) {
        if (ans.find(pos+1) == ans.end()) ans.insert(pos+1);
        return;
    }

    if (visited.find({pos,curr,0}) == visited.end() && throwid[curr] == '0' || throwid[curr] == '?') {
        visited.insert({pos,curr,0});
        int newpos = (pos + throwlist[curr])%mod;
        dfs(newpos, curr+1, throwlist, throwid, ans, mod, visited);
    }
    if (visited.find({pos,curr,1}) == visited.end() && throwid[curr] == '1' || throwid[curr] == '?') {
        visited.insert({pos,curr,1});
        int newpos = pos - throwlist[curr];
        if (newpos < 0) newpos += mod;
        dfs(newpos, curr+1, throwlist, throwid, ans, mod, visited);
    }
}

void solve() {
    int n,m,x;
    cin >> n >> m >> x;
    vt<int> c1(m);
    vt<char> c2(m);
    set<int> ans;
    for (int i = 0; i < m; ++i) {
        cin >> c1[i] >> c2[i];
    }

    set<vt<int>> visited;

    dfs(x-1, 0, c1, c2, ans, n, visited);

    cout << ans.size() << "\n";
    for (auto& v:ans) cout << v << " ";
    cout << "\n";
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