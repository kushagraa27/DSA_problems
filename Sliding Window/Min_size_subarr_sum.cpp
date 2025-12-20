// problem: 209. Minimum Size Subarray Sum
// difficulty: medium
// topic: array, binary search, sliding window, prefix sum
// approach: so first i initialised minL as INT_MAX then right pointer from left to right and calculate sum=sum+nums[right] now shrinking condition will be >=target
// if sum>=target then first of all store then lengeth in minL since value greater than target is also allowed and then shrink the window by subtracting left element
// and incrementing left pointer by 1, keep reapeating for whole array and at last if minL is unchanged then return 0 else return minL.
// time:O(n)
// space: O(1)
// link: https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int minL=INT_MAX;
        int sum=0;
        for(int right=0;right<nums.size();right++)
        {   
            sum=sum+nums[right];
            
            while(sum>=target)
            {   
                
            minL= min(minL,right-left+1);
                sum=sum-nums[left];
                left++;
            }
            
        }
        if (minL==INT_MAX)
        return 0;
        return minL;
    }
};
