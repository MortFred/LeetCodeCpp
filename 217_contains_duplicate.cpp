#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {

        std::unordered_set<int> numberSet{};
        for (auto num : nums)
        {
            if (numberSet.contains(num))
                return true;
            numberSet.insert(num);
        }
        return false;
    }
    bool containsDuplicateOld(std::vector<int> &nums)
    {
        std::unordered_set<int> numberSet(nums.begin(), nums.end());
        return {nums.size() != numberSet.size()};
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    Solution s;
    std::vector<int> nums = {1, 2, 3, 4};
    bool res = s.containsDuplicate(nums);
    std::cout << res << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Time taken by program is : " << std::fixed
              << time_taken << std::setprecision(9);
    std::cout << " sec" << std::endl;
    return 0;
}
