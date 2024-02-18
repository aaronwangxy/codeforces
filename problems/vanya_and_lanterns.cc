#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n,l;
    cin >> n >> l;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    double d = 0;
    for (int i = 0; i < n-1; ++i) {
        d = max(d, (a[i+1]-a[i])/(double)2);
    }
    d = max(d, (double)a[0]);
    d = max(d, (double)l-a[n-1]);
    cout << fixed << d << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}