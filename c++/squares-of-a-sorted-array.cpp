class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        
        int left = 0;
        int right = size - 1;
        int index = size - 1;
        
        while (left <= right) {
            int l_num = pow(nums[left], 2);
            int r_num = pow(nums[right], 2);
            if (l_num > r_num) {
                res[index] = l_num;
                left++;
            } else {
                res[index] = r_num;
                right--;
            }
            index--;
        }
        
        return res;
    }
};
