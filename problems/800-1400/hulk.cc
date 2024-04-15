#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    
    string ans;
    int iter = (n-1)/2;
    if (n%2) {
        for (int i = 0; i < iter; ++i) {
            ans += "I hate that I love that ";
        }
        ans += "I hate it\n";
    } else {
        for (int i = 0; i < iter; ++i) {
            ans += "I hate that I love that ";
        }
        ans += "I hate that I love it\n";
    }

    cout << ans;
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