//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPath(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> triangle = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3},
    };
    cout << s.minPath(triangle) << endl;
}