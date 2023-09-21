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
        if (nums.size() < 3)
            return false;
        int mid = INT32_MAX, left = INT32_MAX;

        for (size_t i = 0; i != nums.size(); ++i)
        {
            if (nums[i] < left)
                left = nums[i];
            else if (left < nums[i] & nums[i] < mid)
                mid = nums[i];
            if (nums[i] > mid)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 1, -2, 6};
    bool res = s.increasingTriplet(nums);
    std::cout << res << std::endl;
    return 0;
}
