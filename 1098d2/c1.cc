#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int largest_digit(int d, vt<int>& available_digits) {
    for (int i = available_digits.size()-1; i >= 0; --i) {
        int digit = available_digits[i];
        if (digit <= d) {
            return digit;
        }
    }
    return -1;
}

int smallest_digit(int d, vt<int>& available_digits) {
    for (int i = 0; i < available_digits.size(); ++i) {
        int digit = available_digits[i];
        if (digit >= d) {
            return digit;
        }
    }
    return -1;
}

void solve() {
    ll a, n;
    cin >> a >> n;
    vt<int> available_digits(n);
    for (auto& a : available_digits) cin >> a;
    sort(available_digits.begin(), available_digits.end());

    if (a == 0) {
        cout << available_digits.front() << "\n";
        return;
    }

    vt<int> a_digits;
    ll a_cpy = a;
    while (a_cpy) {
        a_digits.push_back(a_cpy%10);
        a_cpy /= 10;
    }
    reverse(a_digits.begin(), a_digits.end());

    ll ans = LLONG_MAX;
    bool done;
    bool skip;

    // Find largest b smaller than a, a-b
    // 1 less digit
    if (a_digits.size()-1 >= 1) {        
        ll b1 = 0;
        for (int i = 0; i < a_digits.size()-1; ++i) {
            b1 *= 10;
            b1 += available_digits[n-1];
        }
        ans = min(ans, a-b1);
    }

    // Same number of digits (try to make)
    done = false;
    skip = false;
    vt<int> b2_digits;
    for (int i = 0; i < a_digits.size(); ++i) {
        int a_dig = a_digits[i];
        int b_dig = largest_digit(a_dig, available_digits);
        if (b_dig == a_dig) {
            b2_digits.push_back(b_dig);
        }
        if (b_dig < a_dig && b_dig != -1) {
            b2_digits.push_back(b_dig);
            int to_fill = a_digits.size()-b2_digits.size();
            for (int k = 0; k < to_fill; ++k) {
                b2_digits.push_back(available_digits.back());
            }
            break;
        } 
        if (b_dig == -1) {
            // need to iterate backwards and replace a digit with a smaller one
            for (int j = i-1; j >= 0; --j) {
                int b_dig_j = b2_digits[j];
                int replacement = largest_digit(b_dig_j-1, available_digits);
                if (replacement != -1) {
                    b2_digits[j] = replacement;
                    int to_fill = a_digits.size() - b2_digits.size();
                    for (int k = 0; k < to_fill; ++k) {
                        b2_digits.push_back(available_digits.back());
                    }
                    done = true;
                    break;
                } else {
                    b2_digits.pop_back();
                }
            }
            if (done) {
                break;
            } else {
                skip = true;
                break;
            }
            
        }
    }
    if (!skip) {
        ll b2 = 0;
        for (int i = 0; i < b2_digits.size(); ++i) {
            b2 *= 10;
            b2 += b2_digits[i];
        }
        ans = min(ans, a-b2);
    }

    // Find smallest b larger than a, b-a
    // 1 more digit
    ll b3 = available_digits[0];
    if (available_digits[0] == 0) {
        b3 = available_digits[1];
    }
    for (int i = 0; i < a_digits.size(); ++i) {
        b3 *= 10;
        b3 += available_digits[0];
    }
    ans = min(ans, b3-a);

    // Same number of digits (try to make)
    done = false;
    skip = false;
    vt<int> b4_digits;
    for (int i = 0; i < a_digits.size(); ++i) {
        int a_dig = a_digits[i];
        int b_dig = smallest_digit(a_dig, available_digits);
        if (b_dig == a_dig) {
            b4_digits.push_back(b_dig);
        }
        if (b_dig > a_dig) {
            b4_digits.push_back(b_dig);
            int to_fill = a_digits.size()-b4_digits.size();
            for (int k = 0; k < to_fill; ++k) {
                b4_digits.push_back(available_digits.front());
            }
            break;
        } 
        if (b_dig == -1) {
            // need to iterate backwards and replace a digit with a larger one
            for (int j = i-1; j >= 0; --j) {
                int b_dig_j = b4_digits[j];
                int replacement = smallest_digit(b_dig_j+1, available_digits);
                if (replacement != -1) {
                    b4_digits[j] = replacement;
                    int to_fill = a_digits.size() - b4_digits.size();
                    for (int k = 0; k < to_fill; ++k) {
                        b4_digits.push_back(available_digits.front());
                    }
                    done = true;
                    break;
                } else {
                    b4_digits.pop_back();
                }
            }
            if (done) {
                break;
            } else {
                skip = true;
                break;
            }
            
        }
    }
    if (!skip) {
        ll b4 = 0;
        for (int i = 0; i < b4_digits.size(); ++i) {
            b4 *= 10;
            b4 += b4_digits[i];
        }
        ans = min(ans, b4-a);
    }

    cout << ans << "\n";
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