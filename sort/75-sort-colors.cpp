//
// Created by 成翔昊 on 2020/7/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0, blue=nums.size()-1;
        for(int i=red;i<=blue;){
            if (nums[i]==0) {
                swap(nums[i++], nums[red++]);
            } else if (nums[i]==2) {
                swap(nums[i], nums[blue--]);
            } else {
                i++;
            }
        }
    }
};
