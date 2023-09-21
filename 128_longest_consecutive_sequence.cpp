#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int maxLength = 1;
        std::unordered_set<int> numberSet;
        for (int num : nums)
        {
            numberSet.insert(num);
        }
        for (int num : numberSet)
        {
            if (numberSet.count(num - 1) == 0)
            {
                int i = 1;
                while (numberSet.count(num + i) != 0)
                    i++;
                maxLength = std::max(maxLength, i);
            }
        }
        return maxLength;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {0};
    int res = s.longestConsecutive(nums);
    std::cout << res << std::endl;
    return 0;
}
