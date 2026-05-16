#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
Idea: every node "inserted" is odd. Size parity of ancestors switches
note: need odd >= even since even size -> has an odd sized child

some constructions: x = y, straight line
y = x + 1: straight line
y = x + n: straight line + attach children to second node
*/
void solve() {
    int x, y;
    cin >> x >> y;
    
    if (x > y) {
        cout << "NO" << "\n";
        return;
    }
    if (x == 0) {
        if (y%2) {
            cout << "YES" << "\n";
            for (int i = 2; i <= y; ++i) {
                cout << 1 << " " << i << "\n";
            }
        } else {
            cout << "NO" << "\n";
        }
        return;
    }
    cout << "YES" << "\n";
    for (int i = 1; i <= 2*x-1; ++i) {
        cout << i << " " << i+1 << "\n";
    }
    for (int i = 2*x+1; i <= x+y; ++i) {
        cout << 2 << " " << i << "\n";
    }
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