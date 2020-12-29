class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int temp = 0;
        int left = 0;
        int right = 0;
        int minSoFar = INT_MAX;
        for (right = 0; right < nums.size(); right++) {
            temp += nums[right];
            if (temp < s) {
                // do nothing
            } else {
                int currLen = right - left + 1;
                if (currLen < minSoFar) {
                    minSoFar = currLen;
                }
                temp -= nums[left];
                temp -= nums[right];
                left += 1;
                right -= 1;
            }
        }
        return minSoFar == INT_MAX ? 0 : minSoFar;
    }
};
