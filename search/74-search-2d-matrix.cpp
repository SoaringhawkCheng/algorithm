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

        int length = matrix[0].size();
        int width = matrix.size();

        int begin = 0;
        int end = length * width;

        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            int value = matrix[mid / length][mid % length];

            if (value == target) return true;
            else if (value < target) begin = mid + 1;
            else end = mid;
        }
        return false;
    }
};