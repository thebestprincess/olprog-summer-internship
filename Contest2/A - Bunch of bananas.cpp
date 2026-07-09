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
        vector<int> abc(3);
        cin >> abc[0] >> abc[1] >> abc[2];
        
        ll max_mult = 0;
        for (int i = 0; i < 5; ++i)
        {
            sort(abc.begin(), abc.end());

            ++abc[0];
            max_mult = abc[0] * abc[1] * abc[2];
        }

        cout << max_mult << "\n";
    }

    return 0;
}