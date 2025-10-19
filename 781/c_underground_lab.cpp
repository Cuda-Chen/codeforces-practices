#include <bits/stdc++.h>

using namespace std;

const int N = 400005;
int n, m, k;
vector<int> g[N];
int seen[N];
int dfn[N], b[N], t = 0;

void dfs(int u) {
    dfn[++t] = u;
    seen[u] = 1;
    for(auto v : g[u]) {
        if(!seen[v]) {
            dfs(v);
            dfn[++t] = u;
        }
    }       
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(seen, 0, sizeof(seen));
    dfs(1);

    // Divide the tour into k segments, each with at most s = ⌈2n / k⌉ steps.
    int s = (2 * n + k - 1) / k;
    memset(b, 0, sizeof(b));
    b[t] = 1;
    for(int i = 1; i < k; i++)
        b[i] = 1;
    for(int i = k - 1, last = t; i >= 1; i--) {
        if(last - i > s) {
            swap(b[i], b[last - s]);
            last = last - s;
        } else
            last = i;
    }

    // Output each segment as a walk, starting from node 1.
    for(int last = 1, i = 1; i <= t; i++) {
        if(b[i]) {
            printf("%d ", i - last + 1);
            for(int j = last; j <= i; j++)
                printf("%d ", dfn[j]);
            puts("");
            last = i + 1;
        }
    }
    return 0;
}
