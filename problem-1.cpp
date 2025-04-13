// https://leetcode.com/problems/arithmetic-slices/description/
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) {
            int n = nums.size();
            int left=0; int curr=0; int cnt=0;
            for(int i=2; i<n; i++){
                if(nums[i-1] - nums[i-2] == nums[i] - nums[i-1]) curr = left + 1;
                else curr = 0;
                left = curr;
                cnt += curr;
            }
            return cnt;
        }
    };