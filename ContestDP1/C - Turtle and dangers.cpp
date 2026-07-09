#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> danger(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        danger[x][y] = true;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= m; ++y)
        {
            if (danger[x][y])
            {
                dp[x][y] = 0;
                continue;
            }
        
            if (x == 0 && y == 0)
            {
                dp[x][y] = 1;
                continue;
            }

            if (x > 0) dp[x][y] = (dp[x][y] + dp[x - 1][y]) % MOD;
            if (y > 0) dp[x][y] = (dp[x][y] + dp[x][y - 1]) % MOD; 
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}
