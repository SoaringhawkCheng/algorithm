//
// Created by 成翔昊 on 2020/7/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto iter=nums.begin();
        while(iter!=nums.end()) {
            if (*iter < target) iter++;
            else if (*iter==target) return iter-nums.begin();
            else break;
        }
        return iter-nums.begin();
    }
};