#include <iostream>
 
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
 
            for (int i = 1; i <= n; ++i)
            {
                std::cout << (2 * i - 1) * (2 * i + 1); 
                if (i != n) std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
}