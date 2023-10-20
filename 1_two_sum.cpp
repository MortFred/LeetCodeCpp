#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iomanip>
#include <chrono>
#include <unordered_set>

using namespace std;
template class unordered_map<int, int>;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> missingNumbers{};
        for (int i = 0; i != nums.size(); ++i)
        {
            if (missingNumbers.count(target - nums[i]) != 0)
            {
                return {missingNumbers[target - nums[i]], i};
            }
            missingNumbers[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    Solution s;
    std::vector<int> nums = {3, 3};
    int target = 6;
    std::vector<int> res = s.twoSum(nums, target);
    // std::cout << res << std::endl;
    copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));

    // Timer
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Time taken by program is : " << std::fixed
              << time_taken << std::setprecision(9);
    std::cout << " sec" << std::endl;
    return 0;
}
