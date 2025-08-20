#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000000000

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    vector<string> s(n), r(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    
    vector<vector<ll>> dp(n, vector<ll>(2, inf));
    dp[0][0] = 0;
    dp[0][1] = A[0];
    for(int i = 1; i < n; i++) {
        if(s[i - 1] <= s[i])
            dp[i][0] = dp[i - 1][0];
        if(r[i] >= s[i - 1])
            dp[i][1] = dp[i - 1][0] + A[i];
        if(s[i] >= r[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if(r[i] >= r[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + A[i]);
    }
    
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    if(ans == inf)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}
