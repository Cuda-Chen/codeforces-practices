#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1e15

const int N = 1e5 + 7;


// use static allocation to reduce running time
ll A[N];
vector<vector<ll>> g(N);
int seen[N];

void dfs(
    ll src,
    ll m,
    ll &ans
) {
    seen[src] = 1;

    if(A[src] > m)
        return;

    // leaf
    if(g[src].size() == 1 && seen[g[src][0]] == 1 && A[src] <= m) {
        ans++;
        return;
    }

    for(ll v : g[src]) {
        if(seen[v])
            continue;

        if(A[v])
            A[v] += A[src];
        dfs(v, m,  ans);
    }
}

int main() {
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    for(ll i = 0; i < n; i++)
        cin >> A[i];

    for(ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    ll ans = 0;
    dfs(0, m, ans);
    cout << ans;

    return 0;
}
