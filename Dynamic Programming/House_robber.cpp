// problem: 198. House Robber
// difficulty: medium
// topics: array, dynamic programming 
// approach: so this is classic skip-or-take problem where at each element we check the maxium price which can be robbed, by checking 2 values, first is previous max
// other is current element plus last to last max, since we cant take adjacent houses, the max out of those two will be taken and repeated for all houses
// at last return the final max at the end.
// time: O(n)
// space: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int curr =max(prev1, nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
