#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 2;
    }
    int f[2] = {0,0};
    for (int i = 0; i < 3; ++i) {
        f[a[i]] += 1;
    }
    if (f[0] >= 2) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                cout << i+1 << endl;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                cout << i+1 << endl;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}