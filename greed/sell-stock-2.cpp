//
// Created by 成翔昊 on 2020/6/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 买卖无数次，相当于算出所有相邻低增值
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            profit += prices[i + 1] > prices[i] ? prices[i + 1] - price[i - 1] : 0;
        }
        return profit;
    }
};