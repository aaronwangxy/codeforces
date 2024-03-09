#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vt<int> dp(n+1,0);
    for (int v : {a,b,c}) {
        if (v <= n) {
            dp[v]=1;
        }
    }
    for (int i = 0; i < n+1; ++i) {
        for (int v : {a,b,c}) {
            if (i-v>0) {
                if (dp[i-v] != 0)
                    dp[i] = max(dp[i],1+dp[i-v]);
            }
        }
    }
    cout << dp[n] << "\n";
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