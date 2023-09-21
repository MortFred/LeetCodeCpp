#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Solution
{
public:
    bool increasingTriplet(std::vector<int> &nums)
    {
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {2, 3, 5, 1, 3};
    bool res = s.increasingTriplet(nums);
    std::cout << res << std::endl;
    return 0;
}
