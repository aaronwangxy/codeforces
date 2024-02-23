#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vt vector
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j+i < n) cout << "  ";
            else cout << (j+i)%n << " ";
        }
        cout << i;
        if (i != 0) cout << " ";
        for (int j = n-1; j > -1; --j) {
            if (j+i >= n) {
                cout << (j+i)%n;
                if ((j+i)!=n) cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        cout << i << " ";
    }
    cout << n << " ";
    for (int i = n-1; i > -1; --i) {
        cout << i;
        if (i != 0)
            cout << " ";
    }
    cout << endl;
    for (int i = n-1; i > -1; --i) {
        for (int j = 0; j < n; ++j) {
            if (j+i < n) cout << "  ";
            else cout << (j+i)%n << " ";
        }
        cout << i;
        if (i != 0) cout << " ";
        for (int j = n-1; j > -1; --j) {
            if (j+i >= n) {
                cout << (j+i)%n;
                if ((j+i)!=n) cout << " ";
            }
        }
        cout << endl;
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