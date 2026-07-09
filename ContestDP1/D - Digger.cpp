#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m));
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y) cin >> dp[x][y];
    }

    int total = 0;
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            if (x == 0 && y == 0)
            {
                total += dp[x][y];
                continue;
            }

            int top = 0;
            int left = 0;
            int topleft = 0;
            
            if (x > 0) top = (dp[x][y] + dp[x - 1][y]) % MOD;
            if (y > 0) left = (dp[x][y] + dp[x][y - 1]) % MOD; 
            if (x > 0 && y > 0) topleft = (dp[x][y] + dp[x - 1][y - 1]) % MOD;

            dp[x][y] = max(top, max(left, topleft));
        }
    }

    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}
