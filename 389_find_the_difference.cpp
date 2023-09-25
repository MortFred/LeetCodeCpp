#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Solution
{
public:
    char findTheDifference(std::string a, std::string b)
    {
        std::unordered_map<char, int> count;
        for (auto c : b)
        {
            count[c] += 1;
        }
        for (auto c : a)
        {
            --count[c];
            if (count[c] == 0)
                count.erase(c);
        }
        return count.begin()->first;
    }
};

int main()
{
    Solution s;
    std::string a{"abcd"};
    std::string b{"abcde"};
    char res = s.findTheDifference(a, b);
    std::cout << res << std::endl;
    return 0;
}
