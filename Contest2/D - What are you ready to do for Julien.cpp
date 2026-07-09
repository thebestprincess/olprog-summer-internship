#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

        string s;
        cin >> s;

        int i = -1;
        bool is_finished = false;
        while (i < n)
        {
            if (i == -1 || s[i] == 'L')
            {
                if (i + m >= n)
                {
                    cout << "YES\n";
                    is_finished = true;
                    break;
                }

                int next_log = -1;
                for (int jump = i + 1; jump <= i + m; ++jump)
                {
                    if (s[jump] == 'L') next_log = jump;
                }

                if (next_log != -1) i = next_log;
                else i += m;
            }
            else if (s[i] == 'W')
            {
                ++i;
                --k;

                if (k < 0)
                {
                    cout << "NO\n";
                    is_finished = true;
                    break;
                }
            }
            else if (s[i] == 'C')
            {
                cout << "NO\n";
                is_finished = true;
                break;
            }
        }

        if (!is_finished) cout << "YES\n";
    }

    return 0;
}
