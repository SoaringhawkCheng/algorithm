//
// Created by 成翔昊 on 2020/6/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    //
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int profit=0;
        int curr_min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profit=max(profit, prices[i]-curr_min);
            curr_min=min(curr_min, prices[i]);
        }
        return profit;
    }
};
