#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Solution
{
public:
    std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
    {
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    std::vector<bool> res = s.kidsWithCandies(candies, extraCandies);
    // std::cout << res << std::endl;
    copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}
