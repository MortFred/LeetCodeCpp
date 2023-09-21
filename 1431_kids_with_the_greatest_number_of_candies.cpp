#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int largest_num_of_candies = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        transform(candies.begin(), candies.end(), back_inserter(res), [&](int kid)
                  { return (kid + extraCandies >= largest_num_of_candies); });
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> res = s.kidsWithCandies(candies, extraCandies);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}
