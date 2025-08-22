#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1000000000000000

int main() {
    ll n;
    cin >> n;
    vector<int> s(n);
    for(ll i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    for(ll len = 1; len <= n; len++) {
        for(ll i = 0; i + len - 1 < n; i++) {
            ll j = i + len - 1;
            if(s[i] == s[j]) {
                if(len == 1 || len == 2)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            for(ll k = 0; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    cout << dp[0][n - 1];

    return 0;
}
