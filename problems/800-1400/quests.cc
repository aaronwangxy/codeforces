#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    int maxb = 0;
    int maxsofar = 0;
    vector<int> prefixsum(n);
    prefixsum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefixsum[i] = prefixsum[i-1] + a[i];
    }
 
    for (int i = 0; i < k; ++i) {
        maxb = max(maxb, b[min(i,n-1)]);
        maxsofar = max(maxsofar, prefixsum[min(i,n-1)] + (k-1-i) * maxb);
    }
 
    cout << maxsofar << endl;
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