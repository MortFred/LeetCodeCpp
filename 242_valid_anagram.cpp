#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, int> count;
        for (auto c : t)
        {
            ++count[c];
        }
        for (auto c : s)
        {
            --count[c];
        }
        for (auto x : count)
        {
            if (x.second != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    std::string s{"anagram"};
    std::string t{"nagaram"};
    bool res = a.isAnagram(s, t);
    std::cout << res << std::endl;
    return 0;
}
