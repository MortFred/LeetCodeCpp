#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iomanip>
#include <chrono>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> anagrams{};
        for (auto str : strs)
        {
            std::string x = str;
            std::sort(x.begin(), x.end());
            anagrams[x].push_back(str);
        }
        std::vector<std::vector<std::string>> res;
        for (auto anagram : anagrams)
        {
            res.push_back(anagram.second);
        }
        return res;
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    Solution s;
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    int extraCandies = 3;
    std::vector<std::vector<std::string>> res = s.groupAnagrams(strs);
    // std::cout << res << std::endl;
    for (auto a : res)
    {
        copy(a.begin(), a.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        std::cout << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();

    double time_taken =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    std::cout << "Time taken by program is : " << std::fixed
              << time_taken << std::setprecision(9);
    std::cout << " sec" << std::endl;
    return 0;
}
