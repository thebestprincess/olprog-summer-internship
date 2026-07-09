#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = n; i > m; --i)
        {
            cout << i << " ";
        }

        for (int i = 1; i <= m; ++i)
        {
            cout << i;
            if (i != m) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
