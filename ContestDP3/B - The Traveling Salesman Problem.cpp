#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> gr(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> gr[i][j];
        }
    }

    if (n == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

    int max_mask = 1 << n;
    vector<vector<int>> dp(max_mask, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < max_mask; mask += 2)
    {
        for (int u = 0; u < n; ++u)
        {
            if (!(mask & (1 << u)) || dp[mask][u] == INF) continue;

            for (int v = 1; v < n; ++v)
            {
                if (!(mask & (1 << v)))
                {
                    int next_mask = mask | (1 << v);
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + gr[u][v]);
                }
            }
        }
    }

    int ans = INF;
    int full_mask = max_mask - 1;

    for (int i = 1; i < n; ++i)
    {
        if (dp[full_mask][i] != INF)
        {
            ans = min(ans, dp[full_mask][i] + gr[i][0]);
        }
    }

    cout << ans << "\n";
    return 0;
}
