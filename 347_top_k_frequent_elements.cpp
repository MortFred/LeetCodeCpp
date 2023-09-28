#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <chrono>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return nums;
        std::unordered_map<int, int> count;
        for (int num : nums)
        {
            ++count[num];
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> top_k;
        for (auto a : count)
        {
            top_k.push({a.second, a.first});
        }
        std::vector<int> ans;
        for (int i = 0; i != k; ++i)
        {
            ans.push_back(top_k.top().second);
            top_k.pop();
        }
        return ans;
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    Solution s;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3, 5, 5, 5, 5};
    int k = 3;
    std::vector<int> res = s.topKFrequent(nums, k);
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
