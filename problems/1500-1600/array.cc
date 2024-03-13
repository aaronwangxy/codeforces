#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;
    vt<int> a(n);
    for (auto& v:a) cin >> v;

    unordered_map<int,int> freq;
    for (auto& v:a) {
        freq[v] += 1;
    }

    if (freq.size() < k) {
        cout << "-1 -1\n";
    } else {
        int curr = freq.size();
        int l = 0;
        int r = n-1;

        while (curr >= k) {
            freq[a[r]] -= 1;
            if (freq[a[r]] == 0) curr -= 1;
            r -= 1;
        }
        r += 1;
        freq[a[r]] = 1;
        curr += 1;
        while (curr >= k) {
            freq[a[l]] -= 1;
            if (freq[a[l]] == 0) curr -= 1;
            l += 1;
        }
        l -= 1;

        cout << l+1 << " " << r+1 << "\n";
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