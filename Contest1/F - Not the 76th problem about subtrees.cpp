#include <iostream>
#include <vector>
#include <string>

struct Node
{
    char color;
    std::vector<int> child;
    int cnt_w = 0;
    int cnt_b = 0;

    Node(char color): color(color)
    {
        if (color == 'W') cnt_w = 1;
        else cnt_b = 1;
    }
};

int counter = 0;

void update_cnts(int current_idx, std::vector<Node>& all_n)
{
    for (int i = 0; i < all_n[current_idx].child.size(); ++i)
    {
        int child_idx = all_n[current_idx].child[i];
        update_cnts(child_idx, all_n);
        
        all_n[current_idx].cnt_b += all_n[child_idx].cnt_b;
        all_n[current_idx].cnt_w += all_n[child_idx].cnt_w;
    }

    if (all_n[current_idx].cnt_b == all_n[current_idx].cnt_w) ++counter;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    if (!(std::cin >> t)) return -1;

    while(t--)
    {
        counter = 0;
        int n;
        std::cin >> n;
        
        std::vector<int> parents(n - 1);
        for (int i = 0; i < n - 1; ++i)
        {
            std::cin >> parents[i]; 
        }
        
        std::string colors;
        std::cin >> colors;
        
        std::vector<Node> all_n;
        all_n.reserve(n);
        
        for (int i = 0; i < n; ++i)
        {
            all_n.push_back(Node(colors[i]));
        }
        
        for (int i = 1; i < n; ++i)
        {
            int iparent = parents[i - 1] - 1;
            all_n[iparent].child.push_back(i); 
        }

        update_cnts(0, all_n);
        std::cout << counter << "\n";
    }

    return 0;
}