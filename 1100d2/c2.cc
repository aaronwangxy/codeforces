#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
When would we flip a positive number? 
Either we flip it back or we don't
    - If we flip it back, an odd number of flips to the right of it
        - In this case, we want to minimize the sum to the left of it
    - If we don't flip it back, an even number of flips to the right of it
        - In this case, we want to maximize the sum to the left of it

1 element: don't do anything
    - pos: don't flip
    - neg: can't do anything
2 element
    - pos, neg: don't do anything
    - pos, pos: don't do anything
    - neg, neg: can't do anything
    - neg, pos: maybe flip 2
3 element
    - neg, neg, neg: can't do anything
    - neg, neg, pos: maybe flip 3
    - neg, pos, neg: reduces down to 2 element case
    - neg, pos, pos: maybe flip 2
        - flip 2: pos, neg, pos
        - flip 3: pos, neg, neg
    - pos, neg, neg: reduces down to 2 element case
    - pos, neg, pos: 
    - pos, pos, neg: reduces down to 2 element case
    - pos, pos, pos: don't do anything
*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    ll abs_total = 0;
    for (auto a : arr) abs_total += abs(a);

    ll abs_cum_sum = 0;
    ll cum_sum = 0;
    ll ans = 0;
    // no flip
    for (auto a : arr) ans += a;
    int ans_i = -1;
    for (int i = n-1; i > 0; --i) {
        if (arr[i] > 0) {
            // If we flip, the max val we can get is the sum of |elements to left| + this value negated + right sum
            ll flip = abs_total - abs_cum_sum - 2*arr[i] + cum_sum;
            if (flip > ans) {
                ans = flip;
                ans_i = i;
            }
        }
        cum_sum += arr[i];
        abs_cum_sum += abs(arr[i]);
    }
    if (ans_i == -1) {
        cout << "0" << "\n\n";
        return;
    }
    vt<int> ansv;
    int par = 1;
    for (int i = ans_i-1; i >= 0; --i) {
        if (par * arr[i] > 0) {
            ansv.push_back(i+1);
            par *= -1;
        }
    }
    ansv.push_back(ans_i+1);
    cout << ansv.size() << "\n";
    for (auto a : ansv) cout << a << " ";
    cout << "\n";
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