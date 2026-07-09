#include <iostream>
 
int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
 
    int t;
    if (std::cin >> t)
    {
        while(t--)
        {
            int x;
            std::cin >> x;
 
            if (x == 67 || x == -67) std::cout << x << std::endl;
            else std::cout << x + 1 << std::endl;
        }
        
    }
 
    return 0;
}