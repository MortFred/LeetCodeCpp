#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iomanip>
#include <chrono>
#include <unordered_set>

using namespace std;

// row contains only 1 of the numbers 1-9
// col contains only 1 of the numbers 1-9
// box contains only 1 of the numbers 1-9

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int size = board.size();
        vector<vector<int>> colValid(size, vector<int>(size));
        vector<vector<int>> rowValid(size, vector<int>(size));
        vector<vector<int>> grid3x3Valid(size, vector<int>(size));

        for (int row{0}; row != size; ++row)
        {
            for (int col{0}; col != size; ++col)
            {

                if (board[row][col] == '.')
                    continue;
                int num{board[row][col] - '0'};
                int k = col / 3 + ((row / 3) * 3);
                if (rowValid[row][num] || colValid[col][num] || grid3x3Valid[k][num])
                    return false;

                rowValid[row][num] = colValid[col][num] = grid3x3Valid[k][num] = 1;
            }
        }
        return true;
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    Solution s;
    vector<vector<char>> board = {{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}};
    bool res = s.isValidSudoku(board);
    std::cout << res << std::endl;

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
