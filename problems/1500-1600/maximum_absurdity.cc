#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;
    vt<ll> x(n);
    for (auto& v:x) cin >> v;

    vt<ll> px = x;
    for (int i = n-2; i > -1; --i) {
        px[i] += px[i+1];
    }
    for (int i = 0; i < n-k; ++i) {
        px[i] -= px[i+k];
    }
    for (int i = 0; i < k-1; ++i) {
        px.pop_back();
    }

    // Goal is to pick 2 indices to maximize sum that are at least k-1 apart. 
    int a=1,b=k+1;
    ll msf=0;
    map<ll,int> mx;
    for (int l=0,r=k; r < n-k+1; ++r,++l) {
        if (mx.find(px[l]) == mx.end()) {
            mx[px[l]] = l;
        }
        if (mx.rbegin()->first + px[r] > msf) {
            msf = mx.rbegin()->first + px[r];
            a = mx.rbegin()->second + 1;
            b = r + 1;
        }
    }
    cout << a << " " << b << "\n";
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