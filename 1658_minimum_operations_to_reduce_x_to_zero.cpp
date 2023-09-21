#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <numeric>

class Solution
{
public:
    int minOperations(std::vector<int> &nums, int x)
    {
        int target = std::reduce(nums.begin(), nums.end()) - x;
        if (target == 0)
        {
            return nums.size();
        }
        int max_len = 0;
        int currSum = 0;
        int left = 0;
        for (int right = 0; right != nums.size(); ++right)
        {
            currSum += nums[right];
            while (currSum > target & left <= right)
            {
                currSum -= nums[left];
                left++;
            }
            if (currSum == target)
            {
                max_len = std::max(max_len, right - left + 1);
            }
        }
        if (max_len == 0)
            return -1;
        return nums.size() - max_len;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {8828, 9581, 49, 9818, 9974, 9869, 9991, 10000, 10000, 10000, 9999, 9993, 9904, 8819, 1231, 6309};
    int x = 134365;
    int res = s.minOperations(nums, x);
    std::cout << res << std::endl;
    return 0;
}
