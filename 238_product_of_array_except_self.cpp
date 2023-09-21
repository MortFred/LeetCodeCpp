
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> left(nums.size(), 1);
        std::vector<int> right(nums.size(), 1);

        for (size_t i = 1; i != nums.size(); ++i)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (size_t i = nums.size() - 2; i != -1; --i)
        {
            right[i] = right[i + 1] * nums[i + 1];
            right[i + 1] *= left[i + 1];
        }
        return right;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> res = s.productExceptSelf(nums);
    copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}
