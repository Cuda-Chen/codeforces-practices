#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(ll i = 0; i < n; i++)
        cin >> A[i];

    vector<vector<ll>> dp(
            n + 1,
            vector<ll>(3, INT_MAX)); // 0: rest, 1: gym, 2: contest
                                     
    dp[0][0] = dp[0][1] = dp[0][2] = 0; // base case
    for(ll i = 1; i <= n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;

        if(A[i - 1] == 1 || A[i - 1] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if(A[i - 1] == 2 || A[i - 1] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}
