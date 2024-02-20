#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m;
    cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vt<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // edge case
    int optimal_d = a[0]-1;
    int max_a=a.size()*3,max_diff=max_a-2*m;
    for (int i = 0; i < m; ++i) {
        if (b[i] > optimal_d) {
            max_diff = max_a - 2*(i) - 3*(m-i);
            break;
        }
    }

    for (int i = 0; i < m; ++i) {
        while (i+1 < m && (b[i+1] == b[i])) continue;
        int d = b[i];
        int l=0,r=a.size();
        while (l < r) {
            int mid = l + (r-l)/2;
            if (a[mid] > d) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        int a_score=2*l + 3*(n-l), b_score=2*(i+1)+3*(m-i-1);
        if (a_score - b_score > max_diff) {
            optimal_d = d;
            max_a = a_score;
            max_diff = a_score - b_score;
        } else if (a_score - b_score == max_diff) {
            if (a_score > max_a) {
                optimal_d = d;
                max_a = a_score;
            }
        }
    }
    
    cout << max_a << ":" << max_a-max_diff << endl;
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