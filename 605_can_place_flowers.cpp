#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        if (n == 0)
        {
            return true;
        }
        int plantedFlowers = 0;

        flowerbed.insert(flowerbed.begin(), {0});
        flowerbed.push_back({0});
        for (auto it = flowerbed.begin() + 1; it < flowerbed.end() - 1; it++)
        {
            if ((*(it - 1) == 0) & (*it == 0) & (*(it + 1) == 0))
            {
                *it = 1;
                plantedFlowers++;
                if (plantedFlowers >= n)
                {
                    return true;
                }
            };
        }
        return false;
    }
};

int main()
{
    Solution s = Solution();
    std::vector<int> flowerbed = {0, 0, 0, 0, 0};
    int n = 3;
    bool res = s.canPlaceFlowers(flowerbed, n);
    std::cout << res << '\n';
    return 0;
}
