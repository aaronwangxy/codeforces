#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

bool distinct(int n) {
    set<int> s;
    while (n) {
        int curr = n%10;
        if (s.find(curr) != s.end()) {
            return false;
        }
        s.insert(curr);
        n /= 10;
    }
    return true;
}

void solve() {
    int y;
    cin >> y;
    int curr = y+1;

    while (!distinct(curr)) {
        curr += 1;
    }
    cout << curr << "\n";
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