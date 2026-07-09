#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LENGTH = 1e6 + 1;
int cnt_a[LENGTH];
int cnt_b[LENGTH];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<int> b(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
            ++cnt_b[b[i]];
        }

        int cnt = 0, good = 0;
        for (int i = 0; i < n; ++i)
        {
            int r = a[i];
            if (cnt_a[r] < cnt_b[r]) ++cnt;
            ++cnt_a[r];

            if (i >= m)
            {
                int l = a[i - m];
                if (cnt_a[l] <= cnt_b[l]) --cnt;
                --cnt_a[l];
            }

            if (i >= m - 1 && cnt >= k) ++good;
        }

        cout << good << "\n";

        for (int i = 0; i < n; ++i) cnt_a[a[i]] = 0;
        for (int i = 0; i < m; ++i) cnt_b[b[i]] = 0;
    }

    return 0;
}