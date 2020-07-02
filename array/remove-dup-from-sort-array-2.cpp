#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() < 2) {
            nums2 = nums1;
            return nums1.size();
        }
        int index = 2; // index指向当前要插入的位置
        for (int i = 2; i < nums1.size(); i++) {
            if (nums1[index - 2] != nums1[i]) nums1[index++] = nums1[i];
        }
        for (int j = 0; j < index; j++) {
            nums2.push_back(nums1[j]);
        }
        return index;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5};
    vector<int> nums2;
    int total = s.removeDuplicates(nums1, nums2);
    cout << total << endl;
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;
}