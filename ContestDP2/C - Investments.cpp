#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
    
        vector<vector<int>> revenue(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> revenue[i][j];
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= j; ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + revenue[i][k]);
                }
            }
        }

        cout << dp[n][m] << "\n";
    }

    return 0;
}
