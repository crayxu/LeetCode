class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int second = target - nums[i];
            if (m.count(second)) {
                res.push_back(i);
                res.push_back(m[second]);
                break;
            }
            m[nums[i]] = i; 
        }
        return res;
    }
};
