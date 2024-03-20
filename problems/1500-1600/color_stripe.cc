#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;
    vt<char> strip(n);
    for (auto& v:strip) cin >> v;

    if (k == 2) {
        // Case 1 ABAB ...
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            if (i%2 == 0 && strip[i] != 'A') {
                cnt1 += 1;
            } else if (i%2 == 1 && strip[i] != 'B') {
                cnt1 += 1;
            }
        }
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i%2 == 0 && strip[i] != 'B') {
                cnt2 += 1;
            } else if (i%2 == 1 && strip[i] != 'A') {
                cnt2 += 1;
            }
        }
        cout << min(cnt1,cnt2) << "\n";
        if (cnt1 < cnt2) {
            for (int i = 0; i < n; ++i) {
                if (i%2) {
                    cout << "B";
                } else {
                    cout << "A";
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (i%2) {
                    cout << "A";
                } else {
                    cout << "B";
                }
            }
        }
    } else {
        int l=0;
        int r=0;
        int cnt = 0;
        string ans = "";
        while (r < n) {
            while (r<n && strip[r] == strip[l]) {
                r++;
            }
            cnt += (r-l)/2;
            // [l,r) are same
            if ((r-l)%2 == 0) {
                // even
                char print = 'A';
                char end = 'B';
                if (strip[l] == 'A') {
                    print = 'B';
                    end = 'C';
                    if (r<n && strip[r] == 'C') {
                        print = 'C';
                        end = 'B';
                    }
                } else if (strip[l] == 'B') {
                    end = 'C';
                    if (r<n && strip[r] == 'C') {
                        end = 'A';
                        print = 'C';
                    }
                } else if (r<n && strip[r] == 'B') {
                    print = 'B';
                    end = 'A';
                }
                for (int i = l; i < r-1; ++i) {
                    if ((i-l)%2==0) {
                        ans += strip[i];
                    } else {
                        ans += print;
                    }
                }
                ans += end;
            } else {
                // odd
                char print = 'A';
                if (strip[l] == 'A') print = 'B';
                for (int i = l; i < r; ++i) {
                    if ((i-l)%2==0) {
                        ans += strip[i];
                    } else {
                        ans += print;
                    }
                }
            }
            l = r;
        }
        cout << cnt << "\n" << ans;
    }
    cout << "\n";
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