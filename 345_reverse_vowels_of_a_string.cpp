#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        size_t i = 0;
        size_t j = s.length() - 1;
        const std::string vowels = "aeiouAEIOU";
        while (i < j)
        {
            if (vowels.find(s[i]) == std::string::npos)
            {
                i++;
                continue;
            }
            if (vowels.find(s[j]) == std::string::npos)
            {
                j--;
                continue;
            }
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

int main()
{
    Solution s;
    std::string input_s = "leetcode";
    std::string res = s.reverseVowels(input_s);
    std::cout << res << std::endl;
    return 0;
}
