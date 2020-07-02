#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(const vector<int> &nums, int target) {
        int first = 0, last = nums.size();
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[first] <= nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) last = mid;
                else first = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[last - 1]) first = mid + 1;
                else last = mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {1};
    vector<int> nums2 = {7,8,9,1,2,3,4,5};
    vector<int> nums3= {5,1,2,3,4};
    cout<<"======================="<<endl;
    cout<<s.search(nums1, 0)<<endl;
    cout<<s.search(nums1, 1)<<endl;
    cout<<s.search(nums1, 2)<<endl;
    cout<<"======================="<<endl;
    cout<<s.search(nums2, 0)<<endl;
    cout<<s.search(nums2, 4)<<endl;
    cout<<s.search(nums2, 7)<<endl;
    cout<<s.search(nums2, 9)<<endl;
    cout<<s.search(nums2, 11)<<endl;
    cout<<"======================="<<endl;
    cout<<s.search(nums3, 0)<<endl;
    cout<<s.search(nums3, 1)<<endl;
    cout<<s.search(nums3, 4)<<endl;
    cout<<s.search(nums3, 5)<<endl;
    cout<<s.search(nums3, 7)<<endl;
    cout<<"======================="<<endl;
}