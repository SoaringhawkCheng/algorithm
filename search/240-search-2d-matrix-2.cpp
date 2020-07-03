//
// Created by 成翔昊 on 2020/7/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) j++;
            if (matrix[i][j] > target) i--;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> nums = {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };

    Solution s = Solution();
    cout << s.searchMatrix(nums, 3) << endl;
    cout << s.searchMatrix(nums, 21) << endl;
    cout << s.searchMatrix(nums, 27) << endl;
}