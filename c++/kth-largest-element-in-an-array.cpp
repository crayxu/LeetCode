class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int kthSmallestIndex = len - k;
        sort(nums.begin(), nums.end());
        return nums[kthSmallestIndex];
    }
};
