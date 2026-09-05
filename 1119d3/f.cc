#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
Forward bubble: reduces inversions by the number of 0s after that 1
Backward bubble: reduces inversions by the number of 1s before that 0
Can ignore starting 0s and ending 1s
Maintain number of forward and backward bubbles
*/
void solve() {
    ll n;
    cin >> n;
    vt<ll> arr(n);
    for (auto& a : arr) cin >> a;
    string s;
    cin >> s;

    vt<ll> post0;
    ll cnt0 = 0;
    for (ll i = n-1; i >= 0; --i) {
        if (arr[i] == 0) {
            cnt0++;
        } else {
            post0.push_back(cnt0);
        }
    }
    vt<ll> pre1;
    ll cnt1 = 0;
    for (ll i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            cnt1++;
        } else {
            pre1.push_back(cnt1);
        }
    }

    vt<ll> ans;
    ll init = 0;
    for (ll i = 0; i < post0.size(); ++i) {
        init += post0[i];
    }
    ans.push_back(init);

    ll fwd = 0;
    ll bwd = 0;
    for (char op : s) {
        if (op == '1') {
            fwd += 1;
            if (post0.size() == 0) {
                ans.push_back(ans.back());
                continue;
            }
            ll num_removed = max(0LL, post0.back() - bwd);
            post0.pop_back();
            ans.push_back(ans.back() - num_removed);
        } else {
            bwd += 1;
            if (pre1.size() == 0) {
                ans.push_back(ans.back());
                continue;
            }
            ll num_removed = max(0LL, pre1.back() - fwd);
            pre1.pop_back();
            ans.push_back(ans.back() - num_removed);
        }
    }

    for (auto a : ans) {
        cout << a << " ";
    }
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