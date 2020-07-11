#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<int>> permutation(vector<int> nums) {
        vector<vector<int>> result;
        if (nums.size()==0) return result;

        unordered_map<int, bool> used;
        for (auto num:nums) used[num]=false;
        vector<int> path;

        permutation(result, used, path, nums);
        return result;
    }

private:
    void permutation(vector<vector<int>> &result, unordered_map<int, bool> &used, vector<int> &path, vector<int> &nums) {
        if (path.size()==nums.size()) {
            result.push_back(path);
            return;
        }
        for (auto num: nums) {
            if (used[num]) continue;
            used[num]=true;
            path.push_back(num);
            permutation(result, used, path, nums);
            path.pop_back(num);
            used[num]=false;
        }
    }
};

