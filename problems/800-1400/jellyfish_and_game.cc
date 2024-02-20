#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (k == 1) {
        if (a[0] < b[b.size()-1]) {
            swap(a[0], b[b.size()-1]);
        }
    } else if (k == 2) {
        if (a[0] < b[b.size()-1]) {
            swap(a[0], b[b.size()-1]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (b[0] < a[a.size()-1]) {
            swap(b[0], a[a.size()-1]);
        }
    } else {
        if (a[0] < b[b.size()-1]) {
            swap(a[0], b[b.size()-1]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (b[0] < a[a.size()-1]) {
            swap(b[0], a[a.size()-1]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // At this point, G has the largest element and J has the smallest element
        // If it's J turn, exchange smallest for largest
        // If it's G turn, exchange back
        int MAX = max(a.back(), b.back());
        int MIN = min(a.front(), b.front());
        if (k%2) {
            swap(a[0],MAX);
        }
    }

    ll j = 0;
    for (auto& v : a) j += v;
    cout << j << endl;
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