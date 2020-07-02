#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(const vector<int> &nums, int target) {
        int first = 0, last = nums.size();
        while (first < last) {
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target) return true;
            if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) last = mid;
                else first = mid + 1;
            } else if (nums[first] > nums[mid]) {
                if (nums[mid] < target && target <= nums[last - 1]) first = mid + 1;
                else last = mid;
            } else {
                first++;
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {3};
    vector<int> nums2 = {4, 5, 1, 1, 1, 2, 2, 3};
    vector<int> nums3 = {3, 3, 3, 4, 4, 5, 1, 1, 1, 2, 3};
    cout<<"======================="<<endl;
    cout << s.search(nums1, 1) << endl;
    cout << s.search(nums1, 3) << endl;
    cout << s.search(nums1, 5) << endl;
    cout<<"======================="<<endl;
    cout << s.search(nums2, 0) << endl;
    cout << s.search(nums2, 1) << endl;
    cout << s.search(nums2, 3) << endl;
    cout << s.search(nums2, 4) << endl;
    cout << s.search(nums2, 5) << endl;
    cout << s.search(nums2, 6) << endl;
    cout<<"======================="<<endl;
    cout << s.search(nums2, 0) << endl;
    cout << s.search(nums2, 1) << endl;
    cout << s.search(nums2, 3) << endl;
    cout << s.search(nums2, 4) << endl;
    cout << s.search(nums2, 5) << endl;
    cout << s.search(nums2, 6) << endl;
    cout<<"======================="<<endl;
}