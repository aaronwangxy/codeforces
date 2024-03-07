#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vt<vt<int>> q(m, vt<int>(2));
    for (auto& v:q) {
        cin >> v[0] >> v[1];
        v[0] -= 1;
        v[1] -= 1;
    }

    // Idea: use a prefix sum array
    // Want to find number of indices l<=k<r that are good
    // Make psum s.t. psum[i] is the number of indices 0<=k<i that are good. 
    // Answer to query is just psum[r] - psum[l]
    vt<int> psum(s.size(),0);
    for (int i = 1; i < s.size(); ++i) {
        psum[i] = psum[i-1];
        if (s[i] == s[i-1]) psum[i] += 1;
    }

    for (auto& v:q) {
        cout << psum[v[1]]-psum[v[0]] << "\n";
    }
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