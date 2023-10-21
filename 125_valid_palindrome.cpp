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
    bool isPalindrome(string s)
    {
        string res{""};
        size_t start{0};
        size_t end{s.size() - 1};
        while (start < end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution s;
    string str = " asdfkl;asdjf; asdf;lkj";
    bool res = s.isPalindrome(str);
    cout << res << endl;

    // Timer
    auto end = chrono::high_resolution_clock::now();
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}
