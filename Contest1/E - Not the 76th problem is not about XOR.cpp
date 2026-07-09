#include <iostream>
#include <vector>
 
int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
 
    int t;
    if (std::cin >> t)
    {
        while(t--)
        {
            int n;
            std::cin >> n;
 
            std::vector<int> v(n);
            for (int i = 0; i < n; ++i) std::cin >> v[i];
            
            int max_xor = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    int current_xor = v[i] ^ v[j];
                    if (current_xor > max_xor) max_xor = current_xor;
                }
            }
        
            std::cout << max_xor << std::endl;
        }
    }
}