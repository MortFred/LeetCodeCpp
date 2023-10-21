#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iomanip>
#include <chrono>
#include <unordered_set>

using namespace std;

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
    auto start = std::chrono::high_resolution_clock::now();

    Solution s;
    std::vector<int> candies{2, 3, 5, 1, 3};
    int extraCandies = 3;
    std::vector<bool> res = s.kidsWithCandies(candies, extraCandies);
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
