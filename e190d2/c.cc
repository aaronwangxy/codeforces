#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
ai, ai+1
to choose an ai+2, it must be one of ai or ai+1 if ai != ai+1 else we can introduce a new card
req: at least 3 cards
1 card: spam that card
2 card: alternate the cards, spam the remainder
3 card: 

always better to pair up? yes, less restrictive
1 1 2 
1 2 1 


p s
p s p s
p s p p2 s2 p2 p s3
*/
void solve() {
    int n;
    cin >> n;
    vt<ll> c(n);
    for (auto& v : c) cin >> v;

    ll ans = 0;
    ll stray = 0;
    ll pair = 0;
    int types = 0;
    for (auto v : c) {
        if (v == 1) {
            stray += 1;
        } else {
            ans += v;
            types += 1;
            pair += max(0LL, v/2-1);
        }
    }
    if (ans + stray < 3) {
        cout << 0 << "\n";
        return;
    }
    if (types == 1) {
        cout << ans + min(pair + 1, stray) << "\n";
        return;
    }
    cout << ans + min(pair, stray) << "\n";
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